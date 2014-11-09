// @file Solution.java
// @desc 和3sum一样的思路
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-09

package hl;

import java.lang.Math;
import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        if (num.length < 3) {
            return Integer.MAX_VALUE;
        }

        int[] sortedNums = Arrays.copyOf(num, num.length);
        Arrays.sort(sortedNums);
        int closest = sortedNums[0] + sortedNums[1] + sortedNums[2];

        for (int i = 0; i < sortedNums.length; i++) {
            int idx1 = i + 1;
            int idx2 = sortedNums.length - 1;
            while (idx1 < idx2) {
                int sum = sortedNums[idx1] + sortedNums[idx2] + sortedNums[i];
                if (Math.abs(sum - target) < Math.abs(closest - target)) {
                    closest = sum;
                }
                if (sum < target) {
                    idx1++;
                } else if (sum > target) {
                    idx2--;
                } else {
                    return target;
                }
            }
        }
        return closest;
    }
}
