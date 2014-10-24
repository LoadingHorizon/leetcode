#include <cassert>
#include "single_number.h"

class TestSolution {
public:
    static void test() {
        int ia[] = {1, 1, 2, 2, 3, 3, 4};
        assert(_solution.singleNumber(ia, 7) == 4);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
