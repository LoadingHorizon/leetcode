#include "rotate_array.h"
#include <cassert>

class TestSolution {
public:
    static void test1() {
        int nums[] = {1, 2, 3, 4, 5, 6, 7};
        int n = sizeof(nums) / sizeof(int);
        int k = 3;

        _solution.rotate(nums, n, k);

        assert(nums[0] == 5);
        assert(nums[1] == 6);
        assert(nums[2] == 7);
        assert(nums[3] == 1);
        assert(nums[4] == 2);
        assert(nums[5] == 3);
        assert(nums[6] == 4);
    }

    static void test2() {
        int nums[] = {1, 2, 3, 4, 5, 6, 7};
        int n = sizeof(nums) / sizeof(int);
        int k = 2;

        _solution.rotate(nums, n, k);

        assert(nums[0] == 6);
        assert(nums[1] == 7);
        assert(nums[2] == 1);
        assert(nums[3] == 2);
        assert(nums[4] == 3);
        assert(nums[5] == 4);
        assert(nums[6] == 5);
    }

    static void test3() {
        int nums[] = {-1, -100, 3, 99};
        int n = sizeof(nums) / sizeof(int);
        int k = 3;

        _solution.rotate(nums, n, k);

        assert(nums[0] == -100);
        assert(nums[1] == 3);
        assert(nums[2] == 99);
        assert(nums[3] == -1);
    }

    static void test4() {
        int nums[] = {1, 2, 3, 4, 5, 6};
        int n = sizeof(nums) / sizeof(int);
        int k = 2;

        _solution.rotate(nums, n, k);

        assert(nums[0] == 5);
        assert(nums[1] == 6);
        assert(nums[2] == 1);
        assert(nums[3] == 2);
        assert(nums[4] == 3);
        assert(nums[5] == 4);
    }

private:
    static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test1();
    TestSolution::test2();
    TestSolution::test3();
    TestSolution::test4();

    return 0;
}
