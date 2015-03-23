// @file number_of_1_bits_hl.hpp
// @desc 计算一个数包含多少个1
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2015-03-23

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // number_1_bits_table[n]为n中包含多少个1
        static const int number_1_bits_table[] = {
            0, 1, 1, 2, 1, 2, 2, 3,
            1, 2, 2, 3, 2, 3, 3, 4,
            1, 2, 2, 3, 2, 3, 3, 4,
            2, 3, 3, 4, 3, 4, 4, 5,
            1, 2, 2, 3, 2, 3, 3, 4,
            2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5,
            3, 4, 4, 5, 4, 5, 5, 6,
        };

        int number_1_bits = 0;
        while (n != 0) {
            number_1_bits += number_1_bits_table[n & 0x3F];
            n >>= 6;
        }

        return number_1_bits;
    }
};
