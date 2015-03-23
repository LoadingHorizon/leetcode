#include "reverse_bits.h"
#include <cassert>

class TestSolution {
public:
    static void test() {
        assert(_solution.reverseBits(0) == 0);
        assert(_solution.reverseBits(1) == 2 ^ 31);
        assert(_solution.reverseBits(2) == 2 ^ 30);
        assert(_solution.reverseBits(43261596) == 964176192);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
