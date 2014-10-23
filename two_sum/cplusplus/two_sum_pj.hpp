#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        std::map<int, int> map;
        std::vector<int> result;
        
        for (int i = 0; i < numbers.size(); ++ i) {
            if (map.find(target - numbers[i]) != map.end()) {
                result.push_back(map[target - numbers[i]]);
                result.push_back(i + 1);
                break;
            }
            map[numbers[i]] = i + 1;
        }
        
        return result;
    }
};