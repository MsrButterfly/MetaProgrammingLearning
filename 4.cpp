//
//  4.cpp
//  MetaProgrammingLearning
//
//  Created by Darren Liu on 13-12-27.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#include <iostream>

template <typename _head, typename _tail>
struct type_list_t {
    typedef _head head;
    typedef _tail tail;
};

struct null_type;

template <typename _type_list, unsigned int _i> struct type_at;

template <typename _head, typename _tail, unsigned int _i>
struct type_at<type_list_t<_head, _tail>, _i> {
    typedef typename type_at<_tail, _i - 1>::type type;
};

template <unsigned int _i>
struct type_at<null_type, _i> {
    typedef null_type type;
};

template <typename _head, typename _tail>
struct type_at<type_list_t<_head, _tail>, 0> {
    typedef _head type;
};

template <typename _type_list, typename append_type> struct append_type_list;

template <typename _head, typename _tail, typename append_type>
struct append_type_list<type_list_t<_head, _tail>, append_type> {
    typedef type_list_t<_head, typename append_type_list<_tail, append_type>::result> result;
};

template <>
struct append_type_list<null_type, null_type> {
    typedef null_type result;
};

template <typename append_type>
struct append_type_list<null_type, append_type> {
    typedef type_list_t<append_type, null_type> result;
};

template <typename _head, typename _tail>
struct append_type_list<null_type, type_list_t<_head, _tail>> {
    typedef type_list_t<_head, _tail> result;
};

typedef type_list_t<int, type_list_t<double, type_list_t<char, null_type>>> type_list_a;

int main(int argc, const char *argv[]) {
    type_at<type_list_a, 0>::type a = 65.67;
    std::cout << a << std::endl;
    type_at<type_list_a, 1>::type b = 65.67;
    std::cout << b << std::endl;
    type_at<type_list_a, 2>::type c = 65.67;
    std::cout << c << std::endl;
    typedef append_type_list<type_list_a, long>::result type_list_b;
    type_at<type_list_b, 3>::type d = 65.67;
    std::cout << d << std::endl;
    typedef append_type_list<type_list_b, type_list_a>::result type_list_c;
    type_at<type_list_c, 6>::type e = 65.67;
    std::cout << e << std::endl;
    return 0;
}
