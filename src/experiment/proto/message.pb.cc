// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* SearchRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SearchRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* SearchResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SearchResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_message_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_message_2eproto() {
  protobuf_AddDesc_message_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "message.proto");
  GOOGLE_CHECK(file != NULL);
  SearchRequest_descriptor_ = file->message_type(0);
  static const int SearchRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchRequest, query_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchRequest, page_number_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchRequest, result_per_page_),
  };
  SearchRequest_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SearchRequest_descriptor_,
      SearchRequest::default_instance_,
      SearchRequest_offsets_,
      -1,
      -1,
      -1,
      sizeof(SearchRequest),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchRequest, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchRequest, _is_default_instance_));
  SearchResponse_descriptor_ = file->message_type(1);
  static const int SearchResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResponse, answer_),
  };
  SearchResponse_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SearchResponse_descriptor_,
      SearchResponse::default_instance_,
      SearchResponse_offsets_,
      -1,
      -1,
      -1,
      sizeof(SearchResponse),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResponse, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResponse, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_message_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SearchRequest_descriptor_, &SearchRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SearchResponse_descriptor_, &SearchResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_message_2eproto() {
  delete SearchRequest::default_instance_;
  delete SearchRequest_reflection_;
  delete SearchResponse::default_instance_;
  delete SearchResponse_reflection_;
}

void protobuf_AddDesc_message_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_message_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rmessage.proto\"L\n\rSearchRequest\022\r\n\005quer"
    "y\030\001 \001(\t\022\023\n\013page_number\030\002 \001(\005\022\027\n\017result_p"
    "er_page\030\003 \001(\005\" \n\016SearchResponse\022\016\n\006answe"
    "r\030\001 \001(\t2:\n\rSearchService\022)\n\006Search\022\016.Sea"
    "rchRequest\032\017.SearchResponseb\006proto3", 195);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message.proto", &protobuf_RegisterTypes);
  SearchRequest::default_instance_ = new SearchRequest();
  SearchResponse::default_instance_ = new SearchResponse();
  SearchRequest::default_instance_->InitAsDefaultInstance();
  SearchResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_message_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_message_2eproto {
  StaticDescriptorInitializer_message_2eproto() {
    protobuf_AddDesc_message_2eproto();
  }
} static_descriptor_initializer_message_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SearchRequest::kQueryFieldNumber;
const int SearchRequest::kPageNumberFieldNumber;
const int SearchRequest::kResultPerPageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SearchRequest::SearchRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SearchRequest)
}

void SearchRequest::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

SearchRequest::SearchRequest(const SearchRequest& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SearchRequest)
}

void SearchRequest::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  query_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  page_number_ = 0;
  result_per_page_ = 0;
}

SearchRequest::~SearchRequest() {
  // @@protoc_insertion_point(destructor:SearchRequest)
  SharedDtor();
}

void SearchRequest::SharedDtor() {
  query_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void SearchRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SearchRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SearchRequest_descriptor_;
}

const SearchRequest& SearchRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

SearchRequest* SearchRequest::default_instance_ = NULL;

SearchRequest* SearchRequest::New(::google::protobuf::Arena* arena) const {
  SearchRequest* n = new SearchRequest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SearchRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:SearchRequest)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(SearchRequest, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<SearchRequest*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(page_number_, result_per_page_);
  query_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool SearchRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SearchRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string query = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_query()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->query().data(), this->query().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SearchRequest.query"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_page_number;
        break;
      }

      // optional int32 page_number = 2;
      case 2: {
        if (tag == 16) {
         parse_page_number:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &page_number_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_result_per_page;
        break;
      }

      // optional int32 result_per_page = 3;
      case 3: {
        if (tag == 24) {
         parse_result_per_page:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &result_per_page_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SearchRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SearchRequest)
  return false;
#undef DO_
}

void SearchRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SearchRequest)
  // optional string query = 1;
  if (this->query().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->query().data(), this->query().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchRequest.query");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->query(), output);
  }

  // optional int32 page_number = 2;
  if (this->page_number() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->page_number(), output);
  }

  // optional int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->result_per_page(), output);
  }

  // @@protoc_insertion_point(serialize_end:SearchRequest)
}

::google::protobuf::uint8* SearchRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SearchRequest)
  // optional string query = 1;
  if (this->query().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->query().data(), this->query().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchRequest.query");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->query(), target);
  }

  // optional int32 page_number = 2;
  if (this->page_number() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->page_number(), target);
  }

  // optional int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->result_per_page(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:SearchRequest)
  return target;
}

int SearchRequest::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:SearchRequest)
  int total_size = 0;

  // optional string query = 1;
  if (this->query().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->query());
  }

  // optional int32 page_number = 2;
  if (this->page_number() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->page_number());
  }

  // optional int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->result_per_page());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SearchRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SearchRequest)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const SearchRequest* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SearchRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SearchRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SearchRequest)
    MergeFrom(*source);
  }
}

void SearchRequest::MergeFrom(const SearchRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SearchRequest)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.query().size() > 0) {

    query_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.query_);
  }
  if (from.page_number() != 0) {
    set_page_number(from.page_number());
  }
  if (from.result_per_page() != 0) {
    set_result_per_page(from.result_per_page());
  }
}

void SearchRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SearchRequest::CopyFrom(const SearchRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SearchRequest::IsInitialized() const {

  return true;
}

void SearchRequest::Swap(SearchRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SearchRequest::InternalSwap(SearchRequest* other) {
  query_.Swap(&other->query_);
  std::swap(page_number_, other->page_number_);
  std::swap(result_per_page_, other->result_per_page_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SearchRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SearchRequest_descriptor_;
  metadata.reflection = SearchRequest_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SearchRequest

// optional string query = 1;
void SearchRequest::clear_query() {
  query_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& SearchRequest::query() const {
  // @@protoc_insertion_point(field_get:SearchRequest.query)
  return query_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SearchRequest::set_query(const ::std::string& value) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SearchRequest.query)
}
 void SearchRequest::set_query(const char* value) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SearchRequest.query)
}
 void SearchRequest::set_query(const char* value, size_t size) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SearchRequest.query)
}
 ::std::string* SearchRequest::mutable_query() {
  
  // @@protoc_insertion_point(field_mutable:SearchRequest.query)
  return query_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* SearchRequest::release_query() {
  // @@protoc_insertion_point(field_release:SearchRequest.query)
  
  return query_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SearchRequest::set_allocated_query(::std::string* query) {
  if (query != NULL) {
    
  } else {
    
  }
  query_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), query);
  // @@protoc_insertion_point(field_set_allocated:SearchRequest.query)
}

// optional int32 page_number = 2;
void SearchRequest::clear_page_number() {
  page_number_ = 0;
}
 ::google::protobuf::int32 SearchRequest::page_number() const {
  // @@protoc_insertion_point(field_get:SearchRequest.page_number)
  return page_number_;
}
 void SearchRequest::set_page_number(::google::protobuf::int32 value) {
  
  page_number_ = value;
  // @@protoc_insertion_point(field_set:SearchRequest.page_number)
}

// optional int32 result_per_page = 3;
void SearchRequest::clear_result_per_page() {
  result_per_page_ = 0;
}
 ::google::protobuf::int32 SearchRequest::result_per_page() const {
  // @@protoc_insertion_point(field_get:SearchRequest.result_per_page)
  return result_per_page_;
}
 void SearchRequest::set_result_per_page(::google::protobuf::int32 value) {
  
  result_per_page_ = value;
  // @@protoc_insertion_point(field_set:SearchRequest.result_per_page)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SearchResponse::kAnswerFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SearchResponse::SearchResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SearchResponse)
}

void SearchResponse::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

SearchResponse::SearchResponse(const SearchResponse& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SearchResponse)
}

void SearchResponse::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  answer_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

SearchResponse::~SearchResponse() {
  // @@protoc_insertion_point(destructor:SearchResponse)
  SharedDtor();
}

void SearchResponse::SharedDtor() {
  answer_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void SearchResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SearchResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SearchResponse_descriptor_;
}

const SearchResponse& SearchResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

SearchResponse* SearchResponse::default_instance_ = NULL;

SearchResponse* SearchResponse::New(::google::protobuf::Arena* arena) const {
  SearchResponse* n = new SearchResponse;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SearchResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:SearchResponse)
  answer_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool SearchResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SearchResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string answer = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_answer()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->answer().data(), this->answer().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SearchResponse.answer"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SearchResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SearchResponse)
  return false;
#undef DO_
}

void SearchResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SearchResponse)
  // optional string answer = 1;
  if (this->answer().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchResponse.answer");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->answer(), output);
  }

  // @@protoc_insertion_point(serialize_end:SearchResponse)
}

::google::protobuf::uint8* SearchResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SearchResponse)
  // optional string answer = 1;
  if (this->answer().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->answer().data(), this->answer().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchResponse.answer");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->answer(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:SearchResponse)
  return target;
}

int SearchResponse::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:SearchResponse)
  int total_size = 0;

  // optional string answer = 1;
  if (this->answer().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->answer());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SearchResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SearchResponse)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const SearchResponse* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SearchResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SearchResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SearchResponse)
    MergeFrom(*source);
  }
}

void SearchResponse::MergeFrom(const SearchResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SearchResponse)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.answer().size() > 0) {

    answer_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.answer_);
  }
}

void SearchResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SearchResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SearchResponse::CopyFrom(const SearchResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SearchResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SearchResponse::IsInitialized() const {

  return true;
}

void SearchResponse::Swap(SearchResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SearchResponse::InternalSwap(SearchResponse* other) {
  answer_.Swap(&other->answer_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SearchResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SearchResponse_descriptor_;
  metadata.reflection = SearchResponse_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SearchResponse

// optional string answer = 1;
void SearchResponse::clear_answer() {
  answer_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& SearchResponse::answer() const {
  // @@protoc_insertion_point(field_get:SearchResponse.answer)
  return answer_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SearchResponse::set_answer(const ::std::string& value) {
  
  answer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SearchResponse.answer)
}
 void SearchResponse::set_answer(const char* value) {
  
  answer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SearchResponse.answer)
}
 void SearchResponse::set_answer(const char* value, size_t size) {
  
  answer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SearchResponse.answer)
}
 ::std::string* SearchResponse::mutable_answer() {
  
  // @@protoc_insertion_point(field_mutable:SearchResponse.answer)
  return answer_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* SearchResponse::release_answer() {
  // @@protoc_insertion_point(field_release:SearchResponse.answer)
  
  return answer_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SearchResponse::set_allocated_answer(::std::string* answer) {
  if (answer != NULL) {
    
  } else {
    
  }
  answer_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), answer);
  // @@protoc_insertion_point(field_set_allocated:SearchResponse.answer)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
