#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '(': case '[': case '{':
                char_stack.push(s[i]);
                break;
            case ')':
                if (char_stack.empty()) {
                    return false;
                }
                if (char_stack.top() != '(') {
                    return false;
                }
                char_stack.pop();
                break;
            case ']':
                if (char_stack.empty()) {
                    return false;
                }
                if (char_stack.top() != '[') {
                    return false;
                }
                char_stack.pop();
                break;
            case '}':
                if (char_stack.empty()) {
                    return false;
                }
                if (char_stack.top() != '{') {
                    return false;
                }
                char_stack.pop();
                break;
            default:
                break;
            }
        }

        return char_stack.empty();
    }
};


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
