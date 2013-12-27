//
//  2.cpp
//  MetaProgrammingLearning
//
//  Created by Darren Liu on 13-12-26.
//  Copyright (c) 2013年 mashiroLab. All rights reserved.
//

#include <iostream>

template <int _dim, typename _t>
struct _dot_product {
    static _t result(_t *a, _t *b) {
        return (*a) * (*b) + _dot_product<_dim - 1, _t>::result(a + 1, b + 1);
    }
};

template <typename _t>
struct _dot_product<1, _t> {
    static _t result(_t *a, _t *b) {
        return (*a) * (*b);
    }
};

// Function template partial specialization is not allowed. So following implementation is invalid.
//
// template <int _dim, typename _t>
// inline _t _dot_product(_t *a, _t *b) {
//     return (*a) * (*b) + _dot_product<_dim - 1, _t>(a + 1, b + 1);
// }
//
// template <typename _t>
// inline _t _dot_product<0, _t>(_t *a, _t *b) {
//     return (*a) * (*b);
// }


template <int _dim, typename _t>
inline _t dot_product(_t *a, _t *b) {
    return _dot_product<_dim, _t>::result(a, b);
}

int main(int argc, const char *argv[]) {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};
    std::cout << dot_product<4>(a, b) << std::endl;
    return 0;
}
