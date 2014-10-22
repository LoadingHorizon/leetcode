// @file median_of_two_sorted_arrays_hl.hpp
// @auth hele01(hele01@baidu.com)
// @vers 1.0
// @date 2014-10-22
// @desc 类似于归并排序的思路

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int count = 0;
        int stop = (m + n) / 2;
        
        int a_idx = 0;
        int b_idx = 0;

        int median1 = 0;
        int median2 = 0;
        while (a_idx < m && b_idx < n) {
            count++;
            if (count < stop) {
                if (A[a_idx] < B[b_idx]) {
                    a_idx++;
                } else {
                    b_idx++;
                }
            } else if (count == stop) {
                if (A[a_idx] < B[b_idx]) {
                    median1 = A[a_idx];
                    a_idx++;
                } else {
                    median1 = B[b_idx];
                    b_idx++;
                }
            } else {
                if (A[a_idx] < B[b_idx]) {
                    median2 = A[a_idx];
                } else {
                    median2 = B[b_idx];
                }
                break;
            }
        }

        if (count <= stop) {
            while (a_idx < m) {
                count++;
                if (count < stop) {
                    a_idx++;
                } else if (count == stop) {
                    median1 = A[a_idx];
                    a_idx++;
                } else {
                    median2 = A[a_idx];
                    break;
                }
            }

            while (b_idx < n) {
                count++;
                if (count < stop) {
                    b_idx++;
                } else if (count == stop) {
                    median1 = B[b_idx];
                    b_idx++;
                } else {
                    median2 = B[b_idx];
                    break;
                }
            }
        }

        if ((m + n) % 2 == 1) {
            return static_cast<double>(median2);
        } else {
            return (median1 + median2) / 2.0;
        }
    }
};
