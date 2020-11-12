#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutation;
        
        do {
            //permutation.emplace_back(nums);
            permutation.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        return permutation;
    }
};