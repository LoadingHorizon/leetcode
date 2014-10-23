#include <assert.h>
#include "longest_substring_without_repeating_characters.h"

#include <iostream>
class TestSolution {
public:
    static void test() {
        assert(_solution.lengthOfLongestSubstring("abcabcbb") == 3);
        assert(_solution.lengthOfLongestSubstring("bbbb") == 1);
        assert(_solution.lengthOfLongestSubstring("bcb") == 2);
        assert(_solution.lengthOfLongestSubstring("ruowzgiooobpple") == 7);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test();

    return 0;
}
