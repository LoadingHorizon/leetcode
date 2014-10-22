#include "median_of_two_sorted_arrays.h"
#include <iostream>

bool double_equal(double d1, double d2)
{
    const static double PEC = 0.0001;
    return (d1 - d2 < PEC) && (d2 - d1 < PEC);
}

class TestSolution {
public:
    static void test1() {
        int a[] = {1, 4, 8};
        int b[] = {1, 6, 9, 10, 20, 20};
        assert(double_equal(8, _solution.findMedianSortedArrays(a, 3, b, 6)));
    }
    static void test2() {
        int a[] = {};
        int b[] = {1};
        assert(double_equal(1, _solution.findMedianSortedArrays(a, 0, b, 1)));
    }
    static void test3() {
        int a[] = {1, 1};
        int b[] = {1, 2};
        assert(double_equal(1, _solution.findMedianSortedArrays(a, 2, b, 2)));
    }
    static void test4() {
        int a[] = {1, 2};
        int b[] = {1, 1};
        assert(double_equal(1, _solution.findMedianSortedArrays(a, 2, b, 2)));
    }
    static void test5() {
        int a[] = {3};
        int b[] = {1, 2};
        assert(double_equal(2, _solution.findMedianSortedArrays(a, 1, b, 2)));
    }
    static void test6() {
        int a[] = {};
        int b[] = {2, 3};
        assert(double_equal(2.5, _solution.findMedianSortedArrays(a, 0, b, 2)));
    }
    static void test7() {
        int a[] = {3, 4};
        int b[] = {};
        assert(double_equal(3.5, _solution.findMedianSortedArrays(a, 2, b, 0)));
    }
    static void test8() {
        int a[] = {10000};
        int b[] = {10001};
        assert(double_equal(10000.5, _solution.findMedianSortedArrays(a, 1, b, 1)));
    }
    static void test9() {
        int a[] = {3};
        int b[] = {1, 2, 4};
        assert(double_equal(2.5, _solution.findMedianSortedArrays(a, 1, b, 3)));
    }

private:
    static bool _test_case();
    static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test1();
    TestSolution::test2();
    TestSolution::test3();
    TestSolution::test4();
    TestSolution::test5();
    TestSolution::test6();
    TestSolution::test7();
    TestSolution::test8();
    TestSolution::test9();

    return 0;
}
