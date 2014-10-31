// @file Solution.java
// @desc 把numbers放入一个hashtable中，
//      查找对于numbers中的数n，只需要判断hashtable中存在target - n
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-31

package hl;

import java.util.Hashtable;

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Hashtable<Integer, Integer> num_index_map = new Hashtable<Integer, Integer>();
        for (int idx = 0; idx < numbers.length; idx++) {
            if (num_index_map.containsKey(target - numbers[idx])) {
                return new int[]{num_index_map.get(target - numbers[idx]) + 1, idx + 1};
            }
            num_index_map.put(numbers[idx], idx);
        }
        return new int[]{0, 0};
    }
}
