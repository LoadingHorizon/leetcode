#include <cassert>
#include <string>
#include "reverse_words_in_a_string.h"

class TestSolution {
public:
    static void test1() {
        std::string str = "the sky is blue";
        _solution.reverseWords(str);
        assert(str == "blue is sky the");
    }
    static void test2() {
        std::string str = "  ";
        _solution.reverseWords(str);
        assert(str == "");
    }
    static void test3() {
        std::string str = "  a  b  ";
        _solution.reverseWords(str);
        assert(str == "b a");
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
