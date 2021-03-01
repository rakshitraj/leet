#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType){
        std::sort(candyType.begin(), candyType.end());

        int count = 1;
        for (int i =1; i<candyType.size() && count < candyType.size()/2; i++){
            if (candyType[i] > candyType[i-1]) count++;
        }
        return count;
    }
};