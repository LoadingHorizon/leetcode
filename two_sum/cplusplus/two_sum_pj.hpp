#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> map;
        vector<int> result;
        
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