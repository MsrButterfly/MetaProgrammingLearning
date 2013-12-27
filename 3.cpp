//
//  3.cpp
//  MetaProgrammingLearning
//
//  Created by Darren Liu on 13-12-27.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#include <iostream>

template <bool _c, typename _t1, typename _t2>
struct if_t {};

template <typename _t1, typename _t2>
struct if_t<true, _t1, _t2> {
    typedef _t1 type;
};

template <typename _t1, typename _t2>
struct if_t<false, _t1, _t2> {
    typedef _t2 type;
};

int main(int argc, const char *argv[]) {
    if_t<true, int, char>::type a = 'A';
    std::cout << a << std::endl;
    if_t<false, int, char>::type b = 'A';
    std::cout << b << std::endl;
    return 0;
}
