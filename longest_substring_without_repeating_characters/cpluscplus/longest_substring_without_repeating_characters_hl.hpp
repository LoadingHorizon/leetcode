// @file longest_substring_without_repeating_characters_hl.hpp
// @auth hele01(hele01@baidu.com)
// @vers 1.0
// @date 2014-10-23
// @desc 

#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string &str) {
        for (int i = 0; i < 128; i++) {
            _char_indexs[i] = -1;
        }

        int idx1 = 0;
        int idx2 = 0;
        int length = 0;
        for (idx2 = 0; idx2 < str.length(); idx2++) {
            if (_char_indexs[static_cast<uint32_t>(str[idx2])] < idx1) {
                _char_indexs[static_cast<uint32_t>(str[idx2])] = idx2;
            } else {
                if (length < idx2 - idx1) {
                    length = idx2 - idx1;
                }
                idx1 = _char_indexs[static_cast<uint32_t>(str[idx2])] + 1;
                _char_indexs[static_cast<uint32_t>(str[idx2])] = idx2;
            }
        }

        if (length < idx2 - idx1) {
            length = idx2 - idx1;
        }

        return length;
    }

private:
    int _char_indexs[128];
};
