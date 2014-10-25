#include <string>

class Solution {
public:
    void reverseWords(std::string& str) {
        size_t len = str.length();
        for (size_t i = 0; i < len / 2; i++) {
            std::swap(str[i], str[len - 1 - i]);
        }

        int idx1 = 0;
        int idx2 = 0;
        for (size_t i = 0; i < len; i++) {
            if (str[i] != ' ') {
                continue;
            }
            idx2 = i - 1;
            while (idx1 < idx2) {
                std::swap(str[idx1++], str[idx2--]);
            }
            idx1 = i + 1;
            idx2 = i + 1;
        }
        idx2 = len - 1;
        while (idx1 < idx2) {
            std::swap(str[idx1++], str[idx2--]);
        }

        // 去掉首尾空格，替换多个空格为一个空格
        idx1 = 0;
        idx2 = 0;
        while (str[idx1] == ' ') {
            idx1++;
        }
        for (size_t i = idx1; i < len; i++) {
            if (str[i] == ' ') {
                str[idx2++] = str[i];
                while (str[++i] == ' ') {
                }
                if (i >= len) {
                    break;
                }
                str[idx2++] = str[i];
            } else {
                str[idx2++] = str[i];
            }
        }

        if (str[idx2 - 1] == ' ') {
            str = str.substr(0, idx2 - 1);
        } else {
            str = str.substr(0, idx2);
        }
    }
};
