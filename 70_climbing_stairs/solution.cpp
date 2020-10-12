#include <iostream>
#include <vector>

class Solution {
    public:
    int climbStairs (int n) {
        std::vector<int> ways = {0, 1, 2};
        ways.reserve(n+1);
        // Base Cases
        if (n<3) return ways[n];

        for (int i=3; i<=n; i++) {
            ways.push_back(ways[i-1] + ways[i-2]);
        }
        return ways[n];
    }
};