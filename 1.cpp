//
//  1.cpp
//  MetaProgrammingLearning
//
//  Created by Darren Liu on 13-12-26.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#include <iostream>

template <unsigned n>
struct factorial
{
    enum {
        value = n * factorial<n - 1>::value
    };
};

template <>
struct factorial<0>
{
    enum {
        value = 1
    };
};

int main(int argc, const char *argv[]) {
    std::cout << factorial<6>::value << std::endl;
    return 0;
}