# include <map>
# include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        map<char, char> m= {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        
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
        if (left.empty()) {
            return true;
        }
        
        return false;
    }
};
