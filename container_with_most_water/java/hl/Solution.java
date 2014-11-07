// @file Solution.java
// @desc 假定假设当前构成最大面积的两条纵线分别为i,j(i < j)
//      对于任意k(i < k < j)，如果ak < min(ai, aj)
//      k和i~j之间的纵线构成的最大面积一定小于i,j构成的面积
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-07

package hl;

import java.lang.Math;

public class Solution {
    public int maxArea(int[] height) {
        int idx1 = 0;
        int idx2 = height.length - 1;
        int h1 = height[idx1];
        int h2 = height[idx2];
        int max = Math.min(h1, h2) * (idx2 - idx1);
        while (idx1 < idx2) {
            if (h1 < h2) {
                while (height[++idx1] < h1 && idx1 < idx2);
                h1 = height[idx1];
                int area = Math.min(h1, h2) * (idx2 - idx1);
                if (max < area) {
                    max = area;
                }
            } else {
                while (height[--idx2] < h2 && idx1 < idx2);
                h2 = height[idx2];
                int area = Math.min(h1, h2) * (idx2 - idx1);
                if (max < area) {
                    max = area;
                }
            }
        }

        return max;
    }
}
