// @file Solution.java
// @desc 这个有个公式，具体这个公式是怎么来的，有兴趣可以了解一下
//      <http://en.wikipedia.org/wiki/Catalan_number>
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-06

package hl;

public class Solution {
    public int numTrees(int n) {
        double c = 1;
        for (int i = 1; i < n; i++) {
            c *= (n + i + 1);
            c /= i;
        }
        c /= n;

        return (int) c;
    }
}
