#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        
        int n = candyType.size();
        std::unordered_set<int> types;

        for (auto el:candyType){
            auto _ = types.insert(el);
        }
        return std::min((n/2), (int)types.size());
    }
};