//
// C++ concurrency in Action.
//

#include <atomic>
#include <algorithm>
#include <condition_variable>
#include <functional>
#include <numeric>
#include <thread>
#include <vector>
#include <deque>
#include <future>
#include <iostream>

class join_threads {
private:
  std::vector<std::thread> &threads;
public:
  explicit join_threads(std::vector<std::thread> &threads_) : threads(threads_) {}
  ~join_threads() {
    for (auto &t:threads) {
      if (t.joinable()) {
        t.join();
      }
    }
  }
};

// thread-safe version based std::mutex and std::condition_variable
template <typename T>
class thread_safe_queue {
private:
  struct node {
    std::shared_ptr<T> data;
    std::unique_ptr<node> next;
  };
  std::mutex head_mutex;
  // smart pointer for automatic memory management(node)
  std::unique_ptr<node> head;

  std::mutex tail_mutex;
  node *tail = nullptr;
  std::condition_variable data_cond;

  // helper function
  node *get_tail() {
    std::lock_guard<std::mutex> lock(tail_mutex);
    return tail;
  }

  // should be called when holding head lock
  std::unique_ptr<node> pop_head() {
    std::unique_ptr<node> old_head = std::move(head);
    head = std::move(old_head->next);
    return old_head;
  }

  // make sure queue is not empty, or it will block
  std::unique_lock<std::mutex> wait_for_data() {
    std::unique_lock<std::mutex> lock(head_mutex);
    data_cond.wait(lock, [this]() { return head.get() != get_tail(); });
    return std::move(lock);
  }

  // blocked pop helper function
  // move ownership of lock
  std::unique_ptr<node> wait_pop_head() {
    std::unique_lock<std::mutex> lock(wait_for_data());
    return pop_head();
  }
  std::unique_ptr<node> wait_pop_head(T &value) {
    std::unique_lock<std::mutex> lock(wait_for_data());
    value = std::move(*head->data);
    return pop_head();
  }

  // non-blocked helper function
  std::unique_ptr<node> try_pop_head() {
    std::unique_lock<std::mutex> lock(head_mutex);
    if (head.get() == get_tail()) {
      return nullptr;
    }
    return pop_head();
  }
  std::unique_ptr<node> try_pop_head(T &value) {
    std::unique_lock<std::mutex> lock(head_mutex);
    if (head.get() == get_tail()) {
      return nullptr;
    }
    value = std::move(*head->data);
    return pop_head();
  }

public:
  thread_safe_queue() : head(new node), tail(head.get()) {};
  thread_safe_queue(const thread_safe_queue &) = delete;
  thread_safe_queue &operator=(const thread_safe_queue &) = delete;

  void push(T data) {
    std::shared_ptr<T> new_data = std::make_shared<T>(std::move(data));
    std::unique_ptr<node> p(new node);
    node *const new_tail = p.get();
    {
      std::lock_guard<std::mutex> lock(tail_mutex);
      tail->data = new_data;
      tail->next = std::move(p);
      tail = new_tail;
    }
    data_cond.notify_one();
  }

  bool empty() {
    std::unique_lock<std::mutex> lock(head_mutex);
    return head.get() == get_tail();
  }

  // non-blocked pop
  std::shared_ptr<T> try_pop() {
    auto old_head = try_pop_head();
    return old_head ? old_head->data : nullptr;
  }
  bool try_pop(T &value) {
    auto old_head = try_pop_head(value);
    return old_head != nullptr;
  }

  // blocked pop
  std::shared_ptr<T> wait_and_pop() {
    auto old_head = wait_pop_head();
    return old_head->data;
  }
  void wait_and_pop(T &value) {
    auto old_head = wait_pop_head(value);
  }
};

// std::packaged_task<> instances are not copyable, just movable,
// you can no longer use std::function<>.
// for the queue entries, because std::function<> requires that
// the stored function objects are copy-constructible.
// This is a simple type-erasure class with a function call operator.
class function_wrapper {
  struct impl_base {
    virtual void call() = 0;
    virtual ~impl_base() = default;
  };
  template <typename F>
  struct impl_type : impl_base {
    F f;
    // forward is necessary
    explicit impl_type(F &&f_) : f(std::forward<F>(f_)) {}
    void call() override { f(); }
  };

  std::unique_ptr<impl_base> impl;
public:
  function_wrapper() = default;

  template <typename F>
  function_wrapper(F &&f):
      impl(new impl_type<F>(std::forward<F>(f))) {}

  // functor
  void operator()() { impl->call(); }

  // movable
  function_wrapper(function_wrapper &&other) noexcept :
      impl(std::move(other.impl)) {}
  function_wrapper &operator=(function_wrapper &&other) noexcept {
    impl = std::move(other.impl);
    return *this;
  }

  // disable copy
  function_wrapper(const function_wrapper &) = delete;
  function_wrapper(function_wrapper &) = delete;
  function_wrapper &operator=(const function_wrapper &)= delete;
};

class thread_pool {
// Note that the order of declaration of the members is important !!
  std::atomic_bool done;
  thread_safe_queue<function_wrapper> work_queue;
  std::vector<std::thread> threads;
  join_threads joiner;

  void worker_thread() {
    while (!done) {
      function_wrapper task;
      if (work_queue.try_pop(task)) {
        task();
      } else {
        std::this_thread::yield();
      }
    }
  }
public:
  // ctor
  thread_pool() : done(false), joiner(threads) {
    unsigned const thread_count = std::thread::hardware_concurrency();
    try {
      for (unsigned i = 0; i < thread_count; ++i) {
        threads.emplace_back(&thread_pool::worker_thread, this);
      }
    }
    catch (...) {
      done = true;
      throw;
    }
  }

  // dtor
  ~thread_pool() {
    done = true;
  }

  template <typename FunctionType>
  std::future<typename std::result_of<FunctionType()>::type>
  submit(FunctionType f) {
    typedef typename std::result_of<FunctionType()>::type result_type;

    std::packaged_task<result_type()> task(std::move(f));
    std::future<result_type> res(task.get_future());

    // packaged_task is movable, implicit convert to function_wrapper
    work_queue.push(std::move(task));
    return res;
  }
};

// exception-safe version
template <typename Iterator, typename T>
struct accumulate_block {
  T operator()(Iterator first, Iterator last) {
    return std::accumulate(first, last, T());
  }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
  unsigned long const length = std::distance(first, last);

  if (!length)
    return init;

  unsigned long const block_size = 25;
  unsigned long const num_blocks = (length + block_size - 1)/block_size;

  std::vector<std::future<T> > futures(num_blocks - 1);
  thread_pool pool;

  Iterator block_start = first;
  for (unsigned long i = 0; i < (num_blocks - 1); ++i) {
    Iterator block_end = block_start;
    std::advance(block_end, block_size);
    futures[i] = pool.submit([=]() -> T {
      return accumulate_block<Iterator, T>()(block_start, block_end);
    });
    block_start = block_end;
  }
  T last_result = accumulate_block<Iterator, T>()(block_start, last);
  T result = init;
  for (unsigned long i = 0; i < (num_blocks - 1); ++i) {
    result += futures[i].get();
  }
  result += last_result;
  return result;
}

// ------------------------------------------------------------------------------------
struct Tester {
  void operator()() {
    // do something
    std::cout << "hello world" << std::endl;
  }
};

struct Num {
  int i;
  Num() : i(10) {}
  void operator()() {}
  // enable move
  Num(Num &&) = delete;
  Num &operator=(Num &&) = delete;

  // disable copy
  Num(const Num &) = delete;
  Num &operator=(const Num &) = delete;

};

// which assumption: T must be also movable
// or add another indirection
template <typename T>
class MovableTest {
private:
  T t;
public:
  // forward is necessary
  MovableTest(T &&t_) : t(std::forward<T>(t_)) {}
  MovableTest(MovableTest &&other) : t(std::move(other.t)) {
  }
  MovableTest &operator=(MovableTest &&other) {
    t = std::move(other.t);
    return *this;
  }
  MovableTest(const MovableTest &) = delete;
  MovableTest &operator=(const MovableTest &) = delete;
};

// the difference with MovableTest and MovableTest2 is
// 2 has a template function, which will accept lvalue reference
// while MovableTest will not accept
// very interesting
struct MovableTest2 {
public:
  template <typename T>
  MovableTest2(T &&t_) {
    T t(t_);
  }

  MovableTest2(MovableTest2 &&other) = default;
  MovableTest2 &operator=(MovableTest2 &&other) = default;

  MovableTest2(const MovableTest2 &) = delete;
  MovableTest2 &operator=(const MovableTest2 &) = delete;
};

template <typename T>
void func(T &&t) {
  std::cout << t << std::endl;
}
// ------------------------------------------------------------------------------------

int main() {
  // ------------------------------------------------
  // function_wrapper simple  test
  Tester tester;
  function_wrapper f(tester);
  f = Tester();

  // Movable test
  int i = 42;
  func(i);

  // num is non-copyable and non-movable is ok
  Num num;
  function_wrapper func(num);
  // ------------------------------------------------

  // simple thread pool which can return value
  thread_pool threads;
  threads.submit(tester).get();

  // simple calculation
  std::future<int> res = threads.submit([]() -> int {
    int res = 0;
    for (int i = 1; i <= 10; ++i) {
      res += i;
    }
    return res;
  });
  std::cout << res.get() << std::endl;

  // parallel_accumulate
  std::vector<int> vec;
  for (int i = 0; i <= 100; ++i) {
    vec.push_back(i);
  }
  std::cout << parallel_accumulate(vec.begin(), vec.end(), 0) << std::endl;
  return 0;
}
