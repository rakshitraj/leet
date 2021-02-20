#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int> rsum;
        rsum.push_back(nums[0]);
        vector<int>::iterator it = nums.begin();

        while(++it != nums.end()){
            rsum.push_back(rsum.back() + *it)
        }  
        return rsum;

    }
};