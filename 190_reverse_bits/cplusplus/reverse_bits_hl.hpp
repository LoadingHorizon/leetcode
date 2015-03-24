// @file reverse_bits_hl.hpp
// @desc 按比特位反转一个数字
// @auth hele01(hele01@baidu.com)
// @vers 1.0
// @date 2015-03-23

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static const int reverse_bits_16_table[] = {
            0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15
        };

        uint32_t reverse_bits = 0;
        for (int i = 0; i < 16; i += 4) {
            reverse_bits += reverse_bits_16_table[n >> (28 - i) & 0xF] << i;
            reverse_bits += reverse_bits_16_table[n >> i & 0xF] << (28 - i);
        }

        return reverse_bits;
    }
};
