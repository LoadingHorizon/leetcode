#include <assert.h>
#include <vector>
#include "two_sum.h"

class TestSolution {
public:
    static void test1() {
        std::vector<int> numbers = {2, 7, 11, 15};
        std::vector<int> result = _solution.twoSum(numbers, 9);
        assert(result[0] == 1);
        assert(result[1] == 2);
    }
    static void test2() {
        std::vector<int> numbers = {3, 2, 4};
        std::vector<int> result = _solution.twoSum(numbers, 6);
        assert(result[0] == 2);
        assert(result[1] == 3);
    }
    static void test3() {
        std::vector<int> numbers = {0, 3, 2, 0};
        std::vector<int> result = _solution.twoSum(numbers, 0);
        assert(result[0] == 1);
        assert(result[1] == 4);
    }
    static void test4() {
        std::vector<int> numbers = {5, 75, 25};
        std::vector<int> result = _solution.twoSum(numbers, 100);
        assert(result[0] == 2);
        assert(result[1] == 3);
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
