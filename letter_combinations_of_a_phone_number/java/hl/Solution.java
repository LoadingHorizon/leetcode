package hl;

import java.util.List;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Arrays;

public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>();
        result.add("");

        for (int i = 0; i < digits.length(); i++) {
            List<String> temp = result;
            result = new ArrayList<String>();
            String digitStr = ctos.get(digits.charAt(i));
            if (digitStr == null) {
                return null;
            }
            for (int j = 0; j < digitStr.length(); j++) {
                for (int k = 0; k < temp.size(); k++) {
                    result.add(temp.get(k) + digitStr.charAt(j));
                }
            }
        }

        return result;
    }

    private static Hashtable<Character, String> ctos = new Hashtable<Character, String>() {{
        put('0', " ");
        put('1', " ");
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};
}
