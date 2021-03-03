//645
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> ans(2);
        std::vector<int> hashSet(nums.size()+1, 0);
        for (auto& num:nums){
            hashSet[num]++;
        }
        for (int i=1; i<hashSet.size(); i++){
            if (hashSet[i] == 2) ans[0] = i;
            if (hashSet[i] == 0) ans[1] = i;
        }
        return ans;
    }
};