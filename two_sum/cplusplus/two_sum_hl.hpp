// @file two_sum_hl.hpp
// @auth hele01(hele01@baidu.com)
// @vers 1.0
// @date 2014-10-22
// @desc 查找一个数组中两个数之和为给定指的数组下标
//      1. 排序
//      2. 从两端向中间靠近，left为左边的数，right为右边的数
//         如果left + right < target，left右移
//         如果left + right > target，right左移
//         如果left + right = target，bingo
//      3. 从原数组中找到下标

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        // 排序
        std::vector<int> sorted_numbers(numbers);
        std::sort(sorted_numbers.begin(), sorted_numbers.end());

        // 找到两个数之和为target
        int idx1 = 0;
        int idx2 = sorted_numbers.size() - 1;
        while (idx1 != idx2) {
            if (sorted_numbers[idx1] + sorted_numbers[idx2] > target) {
                idx2--;
            } else if (sorted_numbers[idx1] + sorted_numbers[idx2] < target) {
                idx1++;
            } else {
                break;
            }
        }

        // 没找到
        if (idx1 == idx2) {
            return {};
        }

        // 找到在原来数组中的下标，返回
        auto it1 = std::find(numbers.begin(), numbers.end(), sorted_numbers[idx1]);
        auto it2 = it1;
        if (sorted_numbers[idx1] != sorted_numbers[idx2]) {
            it2 = std::find(numbers.begin(), numbers.end(), sorted_numbers[idx2]);
        } else {
            it2 = std::find(it1 + 1, numbers.end(), sorted_numbers[idx2]);
        }

        idx1 = it1 - numbers.begin();
        idx2 = it2 - numbers.begin();
        if (idx1 > idx2) {
            std::swap(idx1, idx2);
        }

        return {idx1 + 1, idx2 + 1};
    }
};
