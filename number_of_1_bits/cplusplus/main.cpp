#include "number_of_1_bits.h"
#include <cassert>
#include <iostream>

class TestSolution {
public:
    static void test() {
        assert(_solution.hammingWeight(11) == 3);
        assert(_solution.hammingWeight(0) == 0);
        assert(_solution.hammingWeight(1) == 1);
        assert(_solution.hammingWeight(4) == 1);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
