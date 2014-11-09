package hl;

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;

public class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        HashSet<List<Integer>> result = new HashSet<List<Integer>>();
        int[] sortedNums = Arrays.copyOf(num, num.length);
        Arrays.sort(sortedNums);

        for (int i = 0; i < sortedNums.length; i++) {
            int idx1 = i + 1;
            int idx2 = sortedNums.length - 1;
            while (idx1 < idx2) {
                if (sortedNums[idx1] + sortedNums[idx2] + sortedNums[i] < 0) {
                    idx1++;
                } else if (sortedNums[idx1] + sortedNums[idx2]  + sortedNums[i] > 0) {
                    idx2--;
                } else {
                    if (i < idx1) {
                        result.add(new ArrayList<Integer>(Arrays.asList(
                                        sortedNums[i], sortedNums[idx1], sortedNums[idx2])));
                    } else if (i > idx2) {
                        result.add(new ArrayList<Integer>(Arrays.asList(
                                        sortedNums[idx1], sortedNums[idx2], sortedNums[i])));
                    } else {
                        result.add(new ArrayList<Integer>(Arrays.asList(
                                        sortedNums[idx1], sortedNums[i], sortedNums[idx2])));
                    }
                    idx1++;
                    idx2--;
                }
            }
        }

        return new ArrayList<List<Integer>>(result);
    }
}
