// @file Solution.java
// @desc 要考虑的异常比较多
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-03

package hl;

import java.util.Hashtable;

public class Solution {
    public int atoi(String str) {
        str = str.trim();
        if (str.length() == 0) {
            return 0;
        }

        boolean is_negative = false;
        int idx = 0;
        if (!Character.isDigit(str.charAt(idx))) {
            if (str.charAt(idx) == '-') {
                is_negative = !is_negative;
            } else if (str.charAt(0) == '+') {
                // is positive
            } else {
                return 0;
            }
            idx++;
        }

        long num = 0;
        for (; idx < str.length(); idx++) {
            if (!Character.isDigit(str.charAt(idx))) {
                break;
            }
            num = num * 10 + ctoi.get(str.charAt(idx));
            if (num > Integer.MAX_VALUE) {
                return is_negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
        }

        return is_negative ? - (int) num : (int) num;
    }

    private static Hashtable<Character, Integer> ctoi = new Hashtable<Character, Integer>() {{
        put('0', 0);
        put('1', 1);
        put('2', 2);
        put('3', 3);
        put('4', 4);
        put('5', 5);
        put('6', 6);
        put('7', 7);
        put('8', 8);
        put('9', 9);
    }};
}
