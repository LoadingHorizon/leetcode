// 二分查找
# include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2) {
            return findKthSortedArrays(A, m, B, n, (m + n) / 2);
        } else {
            return (findKthSortedArrays(A, m, B, n, (m + n) / 2) + findKthSortedArrays(A, m, B, n, (m + n) / 2 - 1)) / 2.0;
        }
    }

    int findKthSortedArrays(int A[], int m, int B[], int n, int kth) {
        if (m == 0) {
            return B[kth];
        }

        if (n == 0) {
            return A[kth];
        }

        if (kth == 0) {
            return std::min(A[0], B[0]);
        }

        // double k = 1.0 * kth / (m + n);
        int posA = (m * kth - 1) / (m + n);
        int posB = (n * kth - 1) / (m + n);

        if (A[posA] <= B[posB]) {
            return findKthSortedArrays(A + posA + 1, m - posA - 1, B, n, kth - posA - 1);
        } else {
            return findKthSortedArrays(A, m, B + posB + 1, n - posB - 1, kth - posB - 1);
        }
    }
};
