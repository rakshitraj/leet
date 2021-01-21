// Given an array nums and value val, 
// remove all instances of val in-place and 
// return new length. 
// Elements after the length could be anything

// Limitation: do this by modifying the initial array, O(1) extra memory

#include <iostream>
#include <vector>

class solution {
public:
    int removeELement(std::vector<int> nums, int val) {
        int i=0, cpy=0;
        while(cpy<nums.size()) {
            if (nums[cpy] != val){
                nums[i++] = nums[cpy++];
            }
            else cpy++;
        }
        return i;
    }

};