// @file single_number_ii_hl.hpp
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-24
// @desc 网上找的答案。。。好使，没仔细看，反正我是想不到

#include <vector>

class Solution {
public:
    int singleNumber(int A[], int n) {
        return findNumber(A, n, 3, 1);
    }

    int findNumber(int A[], int size, int m, int n) {
        int mask = -1, i, j;
        std::vector<int> times(m + 1,0);

        for (i = 0; i < size; i++) {
            mask = -1;
            times[0] = -1;
            times[m] = 0;
            for (j = m; j >= 1; --j) {
                times[j] = (times[j] | (times[j - 1] & A[i])) & mask;
                mask &= (~times[j]);
            }
        }
        return times[n];
    }
};
