// @file Solution.java
// @desc 以每一个字符为中心，检查以每个字符为中心回文字串
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-03

package hl;

public class Solution {
    public String longestPalindrome(String src) {
        String palindrome = "";
        for (int idx = 0; idx < src.length(); idx++) {
            // "oxo" => "oxo"
            int m = idx - 1; 
            int n = idx + 1;
            while (m >= 0 && n < src.length()
                    && src.charAt(m) == src.charAt(n)) {
                m--;
                n++;
            }
            if (n - m - 1 > palindrome.length()) {
                palindrome = src.substring(m + 1, n);
            }

            // "oxxo" => "oxxo"
            m = idx;
            n = idx + 1;
            while (m >= 0 && n < src.length()
                    && src.charAt(m) == src.charAt(n)) {
                m--;
                n++;
            }
            if (n - m - 1 > palindrome.length()) {
                palindrome = src.substring(m + 1, n);
            }
        }
        return palindrome;
    }
}
