#include <iostream>
#include <vector>
#include <cassert>
 
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i=1; i < nums.size(); i++) {
            currSum = std::max(nums[i], currSum + nums[i]);
            maxSum = std::max(currSum, maxSum);
        }
        return maxSum;
    }
};

void test(Solution obj) {
    std::vector<int> testcase1 = {-2,1,-3,4,-1,2,1,-5,4};
    int answer1 = 6;
    int output1 = obj.maxSubArray(testcase1);
    assert(answer1 == output1);
}

int main() {
    Solution obj;
    test(obj);
    return 0;
}