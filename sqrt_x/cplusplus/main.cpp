#include <cassert>
#include "sqrt_x.h"

class TestSolution {
public:
    static void test() {
        assert(_solution.sqrt(9) == 3);
        assert(_solution.sqrt(4) == 2);
        assert(_solution.sqrt(100) == 10);
        assert(_solution.sqrt(2147395599) == 46339);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
