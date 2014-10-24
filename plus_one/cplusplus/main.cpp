#include <assert.h>
#include "plus_one.h"

class TestSolution {
public:
    static void test1() {
        std::vector<int> digits;
        digits.push_back(1);
        digits.push_back(2);
        digits.push_back(3);
        std::vector<int> result = _solution.plusOne(digits);
        assert(result[0] == 1);
        assert(result[1] == 2);
        assert(result[2] == 4);
    }
    static void test2() {
        std::vector<int> digits;
        digits.push_back(1);
        digits.push_back(2);
        digits.push_back(9);
        std::vector<int> result = _solution.plusOne(digits);
        assert(result[0] == 1);
        assert(result[1] == 3);
        assert(result[2] == 0);
    }
    static void test3() {
        std::vector<int> digits;
        digits.push_back(9);
        digits.push_back(9);
        digits.push_back(9);
        std::vector<int> result = _solution.plusOne(digits);
        assert(result[0] == 1);
        assert(result[1] == 0);
        assert(result[2] == 0);
        assert(result[3] == 0);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test1();
    TestSolution::test2();
    TestSolution::test3();

    return 0;
}
