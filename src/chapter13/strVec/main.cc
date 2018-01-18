/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#include <iostream>
#include "strVec.h"

int main() {
    int a = 10, b = 20, c = 30;
    a = b = c;
    std::cout << a << " " << b << " " << c << " " << std::endl;

    StrVec svec = {"ok", "you", "ha", "good"};
    for (std::size_t i = 0; i < 20; ++i) {
        svec.push_back(std::to_string(i));
        std::cout << "size: " << svec.size() << " cap: " << svec.capacity() << std::endl;
    }
    svec.resize(10);
    svec.resize(15, "hello");
    for (auto &s:svec) {
        std::cout << s << " ";
    }
    svec.reserve(100);
    std::cout << std::endl;
    std::cout << "size: " << svec.size() << " cap: " << svec.capacity() << std::endl;
    return 0;
}
