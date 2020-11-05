#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
       int evenPos = 0;
       int oddPos = 0;
       for (int i=0; i<position.size(); i++){
           if (position[i]%2 == 0) evenPos++;
           else oddPos++;
       }
       return std::min(evenPos, oddPos);
    }
};