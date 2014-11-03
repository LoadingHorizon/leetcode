// @file Solution.java
// @desc x除以10，y乘以10
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-03

package hl;

public class Solution {
    public int reverse(int x) {
        int y = x % 10;
        x /= 10;
        while (x != 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        return y;
    }
}
