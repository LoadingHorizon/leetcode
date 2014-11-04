// @file Solution.java
// @desc 先把x转成字符串，再判断字符串是否为回文
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-04

package hl;

public class Solution {
    public boolean isPalindrome(int x) {
        String str = String.valueOf(x);
        int m = 0;
        int n = str.length() - 1;
        while (m < n) {
            if (str.charAt(m) != str.charAt(n)) {
                return false;
            }
            m++;
            n--;
        }
        return true;
    }
}
