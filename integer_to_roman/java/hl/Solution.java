// @file Solution.java
// @desc
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-08

package hl;

import java.util.Hashtable;

public class Solution {
    public String intToRoman(int num) {
        int base = 1;
        String roman = "";
        while (num > 0) {
            roman = itor.get((num % 10) * base) + roman;
            base *= 10;
            num /= 10;
        }

        return roman;
    }

    private static Hashtable<Integer, String> itor = new Hashtable<Integer, String>() {{
        put(0, "");
        put(1, "I");
        put(2, "II");
        put(3, "III");
        put(4, "IV");
        put(5, "V");
        put(6, "VI");
        put(7, "VII");
        put(8, "VIII");
        put(9, "IX");
        put(10, "X");
        put(20, "XX");
        put(30, "XXX");
        put(40, "XL");
        put(50, "L");
        put(60, "LX");
        put(70, "LXX");
        put(80, "LXXX");
        put(90, "XC");
        put(100, "C");
        put(200, "CC");
        put(300, "CCC");
        put(400, "CD");
        put(500, "D");
        put(600, "DC");
        put(700, "DCC");
        put(800, "DCCC");
        put(900, "CM");
        put(1000, "M");
        put(2000, "MM");
        put(3000, "MMM");
    }};
}
