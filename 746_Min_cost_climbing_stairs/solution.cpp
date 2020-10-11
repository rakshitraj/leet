#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        std::vector<int> price;
        price.reserve(top);
        // Initial cost of starting point
        price[0] = cost[0];
        price[1] = cost[1];

        for (int i=2; i < top; i++) {
            price[i] = cost[i] + std::min(price[i-1], price[i-2]);
        }
        return std::min(price[top-1], price[top-2]);
    }
};