// @file Solution.java
// @desc 有问题，TODO
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-04

package hl;

public class Solution {
    public boolean isMatch(String s, String p) {
        int idx1 = 0;
        int idx2 = 0;
        
        while (idx1 < s.length() && idx2 < p.length()) {
            if (p.charAt(idx2) == '.') {
                idx1++;
                idx2++;
            } else if (p.charAt(idx2) == '*') {
                idx2++;
                if (idx2 == p.length()) {
                    return true;
                }
                while (idx1 < s.length() && s.charAt(idx1) != p.charAt(idx2)) {
                    idx1++;
                }
                idx1++;
                idx2++;
            } else {
                if (s.charAt(idx1) == p.charAt(idx2)) {
                    idx1++;
                    idx2++;
                } else {
                    return false;
                }
            }
        }

        return (idx1 == s.length() && idx2 == p.length());
    }
}
