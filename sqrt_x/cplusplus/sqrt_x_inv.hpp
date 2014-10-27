// @file sqrt_x_inv.hpp
// @desc 神奇的sqrt实现，在图像处理领域用这种方式实现
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-27

#pragma once
#include <iostream>

// 别问我为什么，我也不知道，只想说神奇，orZ
// http://blog.csdn.net/stormbjm/article/details/8191737
float InvSqrt (float x){
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

class Solution {
public:
    int sqrt(int x) {
        int64_t ret = static_cast<int64_t>(1.0 / InvSqrt(static_cast<float>(x)));
        // InvSqrt计算的是一个近似值，有一点误差
        while ((ret * ret) < x) {
            ret++;
        }
        while ((ret * ret) > x) {
            ret--;
        }
        return ret;
    }
};
