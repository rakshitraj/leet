#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::unordered_map <int, double> dp = {{0,1}};

        for (int key=1; key<=target; key++){
            dp[key] = 0;
            for (auto n: nums) {
                dp[key] += (dp.find(key-n) == dp.end())? 0 : dp[key-n];
            }
        }
        return dp[target];
    }
};