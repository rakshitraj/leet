#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool validate(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/divisor);
            if (sum > threshold) return false;
        }
        return true;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        cin.tie(0);
		cout.tie(0);
		ios_base::sync_with_stdio(false);
        
        int lower_bound = 1;
        int upper_bound = *std::max_element(nums.begin(), nums.end());

        while (lower_bound < upper_bound){
            int mid = (lower_bound + upper_bound)/2;
            if (validate(nums, threshold, mid))
                upper_bound = mid;
            else lower_bound = mid+1;
        }
        return upper_bound;
    }
};