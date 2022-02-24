#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <string>

namespace util {
    template <typename T>
    void printVector(
            std::vector<T> vec,
            std::string (*transform)(T),
            std::string vecname = "noname vec"
        ) {
        std::cout << vecname << ": ";

        int i = 0;
        for (const T& v : vec) {
            std::cout << ++i << ": " << transform(v) << ", ";
        }
        std::cout << "\n";
    }
}

#endif