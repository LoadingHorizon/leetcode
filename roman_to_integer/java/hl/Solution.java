// @file Solution.java
// @desc <http://baike.baidu.com/view/42061.htm?fr=aladdin>
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-08

package hl;

import java.util.Hashtable;

public class Solution {
    public int romanToInt(String s) {
        if (s.length() == 1) {
            return ctoi.get(s.charAt(0));
        }
        int idx = 0;
        int ret = ctoi.get(s.charAt(0));
        int num = ctoi.get(s.charAt(1));
        // 小的数字，（限于Ⅰ、X 和C）在大的数字的左边
        // 所表示的数等于大数减小数得到的数
        if (ret < num) {
            return romanToInt(s.substring(1)) - ret;
        }
        // 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数
        while (ctoi.get(s.charAt(idx)) < num) {
            idx++;
            if (idx == s.length()) {
                return ret;
            }
            ret += num;
            num = ctoi.get(s.charAt(idx));
        }

        return ret + romanToInt(s.substring(idx + 1));
    }

    private static Hashtable<Character, Integer> ctoi = new Hashtable<Character, Integer>() {{
        put('I', 1);
        put('V', 5);
        put('X', 10);
        put('L', 50);
        put('C', 100);
        put('D', 500);
        put('M', 1000);
    }};
};
