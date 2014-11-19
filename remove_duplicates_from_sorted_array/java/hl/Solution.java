// @file Solution.java
// @desc 遍历一遍就可以了
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-19

package hl;

public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length == 0 || A.length == 1) {
            return A.length;
        }

        int pos = 1;
        for (int i = 1; i < A.length; i++) {
            while (A[i] == A[i - 1]) {
                if (++i >= A.length) {
                    return pos;
                }
            }
            A[pos++] = A[i];
        }
        return pos;
    }
}
