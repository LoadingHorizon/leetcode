// @file Solution.java
// @desc 用第一个字符串一次匹配各个字符串
//      如果匹配失败就去掉最后一个字符
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-08

package hl;

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        String prefix = strs[0];
        for (String str : strs) {
            while (!str.startsWith(prefix)) {
                prefix = prefix.substring(0, prefix.length() - 1);
            }
        }
        return prefix;
    }
}
