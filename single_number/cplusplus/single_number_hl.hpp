// @file single_number_hl.hpp
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-24
// @desc 用到一些数学知识
//      1. 两个相同的数异或为0， A ^ A = 0
//      2. 交换律，A ^ B = B ^ A
//      3. 如果A与X异或得到B，则A与B异或能得到X，A ^ X = B => X = A ^ B

class Solution {
public:
    int singleNumber(int A[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum ^= A[i];
        }
        return sum;
    }
};
