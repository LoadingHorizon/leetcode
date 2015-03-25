#include <cstring>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int* nums_copy = new int[n];
        memcpy(nums_copy, nums, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = nums_copy[i];
        }
        delete[] nums_copy;
    }
};
