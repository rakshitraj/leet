#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
      vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto got = m.find(target - nums[i]);
            if (got == m.end()) {
                m[nums[i]] = i;
            } else {
                res.push_back(got->second);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}