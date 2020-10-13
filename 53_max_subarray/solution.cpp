#include <iostream>
#include <vector>
#include <cassert>
 
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        std::vector<int> current_max_sum;
        std::vector<int> max_sum;
        
        // Base case
        int max = nums[0];
        max_sum.push_back(nums[0]);
        current_max_sum.push_back(nums[0]);
        
        
        for (int i=1; i<nums.size(); i++) {
            
            if ((nums[i] + current_max_sum[i-1]) > nums[i]) {
                current_max_sum[i] = nums[i] + current_max_sum[i-1];
                
            }
            else {
                current_max_sum[i] = nums[i];
            }
            
            if (current_max_sum[i] > max)
                    max = current_max_sum[i];
            
            max_sum.push_back(max);
        }
        return max_sum.back();
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