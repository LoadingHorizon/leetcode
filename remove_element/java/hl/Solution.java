// @file Solution.java
// @desc 用两个指针遍历一边
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-19

package hl;

public class Solution {
    public int removeElement(int[] A, int elem) {
        int pos = 0;
        for (int i = 0; i < A.length; i++) {
            while (A[i] == elem) {
                if (++i >= A.length) {
                    return pos;
                }
            }
            A[pos++] = A[i];
        }
        return pos;
    }
}
