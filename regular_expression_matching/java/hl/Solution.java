// @file Solution.java
// @desc 看起来挺简单的，写起来这么恶心。。。
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-04

package hl;

import java.util.regex.Pattern;

public class Solution {
    public boolean isMatch(String s, String p) {
        return Pattern.compile(p).matcher(s).matches();
    }
}
