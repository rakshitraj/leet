#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> out;
        deque <int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // remove values from the right of the deque
            // if they are smaller than the new value to be inserted
            while (!window.empty() && nums[i] >= nums[window.back()])
                window.pop_back();
            
            // insert the new value
            window.push_back(i);
            
            // remove values that have already been passed (window of (k-i, i])
            if (window.front() <= i - k)
                window.pop_front();
            
            // starting at i == k - 1 (window of [0, k))
			// push the leftmost value (the maximum) to the output
            if (i >= k - 1)
                out.push_back(nums[window.front()]);
        }
        return out;
    }
};