# include <map>
# include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> left;
        const static std::map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                left.push(s[i]);
            } else {
                if ((!left.empty()) && (s[i] == m[left.top()])) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        
        return left.empty();
    }
};
