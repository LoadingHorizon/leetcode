#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> result(digits);
        int index = digits.size() - 1;
        result[index]++;

        while (result[index] == 10 && index >= 1) {
            result[index] = 0;
            result[--index]++;
        }
        
        if (result[0] == 10) {
            result[0] = 1;
            result.push_back(0);
        }

        return result;
    }
};
