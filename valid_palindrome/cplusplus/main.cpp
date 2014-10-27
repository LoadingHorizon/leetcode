#include <cassert>
#include <string>
#include "valid_palindrome.h"

class TestSolution {
public:
    static void test() {
        assert(_solution.isPalindrome("A man, a plan, a canal: Panama"));
        assert(!_solution.isPalindrome("race a car"));
        assert(_solution.isPalindrome(""));
        assert(_solution.isPalindrome(",."));
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
