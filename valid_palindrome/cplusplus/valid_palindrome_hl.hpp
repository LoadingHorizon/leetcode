// @file valid_palindrome_hl.hpp
// @desc 一个字符串中的字母数字是否是回文
//      字母忽略大小写
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-27

#pragma once

#include <ctype.h>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& str) {
        int idx1 = 0;
        int idx2 = str.length() - 1;

        while (idx1 < idx2) {
            while (!isalnum(str[idx1])) {
                idx1++;
                if (idx1 >= idx2) {
                    return true;
                }
            }
            while (!isalnum(str[idx2])) {
                idx2--;
                if (idx1 >= idx2) {
                    return true;
                }
            }
            if (tolower(str[idx1]) != tolower(str[idx2])) {
                return false;
            }
            idx1++;
            idx2--;
        }

        return true;
    }
};
