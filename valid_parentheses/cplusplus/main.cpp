#include <valid_parentheses.h>

class TestSolution {
public:
    static void test() {
        assert(_solution.isValid("()"));
        assert(_solution.isValid("()[]{}"));
        assert(!_solution.isValid("(]"));
        assert(!_solution.isValid("([)]"));
    }

private:
    static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
