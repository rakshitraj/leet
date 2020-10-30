#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        std::map<int, int> pairs;
        int count =0;

        for (int i=0; i< nums.size(); i++) {
            if(pairs.find(nums[i]) != pairs.end()) pairs[nums[i]]++;
            else{
                pairs[nums[i]] = 1;
            }
        }
        // If a number occurs n times, there are n*(n-1)//2 viable piars
        for (auto el: pairs){
            count+= (el.second * (el.second - 1)) / 2;
        }

        return count;
    }
};