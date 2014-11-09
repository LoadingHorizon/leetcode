// @file Solution.java
// @desc 和3sum一样的思路，比3sum多一层循环
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-09

package hl;

import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        if (num.length < 4) {
            return new ArrayList<List<Integer>>();
        }

        HashSet<List<Integer>> result = new HashSet<List<Integer>>();
        int[] sortedNums = Arrays.copyOf(num, num.length);
        Arrays.sort(sortedNums);

        for (int i = 0; i < sortedNums.length; i++) {
            for (int j = i + 1; j < sortedNums.length; j++) {
                int idx1 = j + 1;
                int idx2 = sortedNums.length - 1;
                while (idx1 < idx2) {
                    int sum = sortedNums[i] + sortedNums[j]
                        + sortedNums[idx1] + sortedNums[idx2];
                    if (sum < target) {
                        idx1++;
                    } else if (sum > target) {
                        idx2--;
                    } else {
                        result.add(new ArrayList<Integer>(Arrays.asList(
                                        sortedNums[i], sortedNums[j],
                                        sortedNums[idx1], sortedNums[idx2])));
                        idx1++;
                        idx2--;
                    }
                }

            }
        }

        return new ArrayList<List<Integer>>(result);
    }
}
