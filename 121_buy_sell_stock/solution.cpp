/**
 * Pair of buy and sell days for maximum profit.
 * return max profit
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT32_MAX;
        int maxProfit = 0;

        for (int e: prices){
            if (e < minPrice) {
                minPrice = e;
            }
            else if (e - minPrice > maxProfit)
                maxProfit = e - minPrice;
        }
        return maxProfit;
    }
};