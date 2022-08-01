#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 2D vector for mxn grid and set values to 1
        vector<vector<int>> dp(m, vector<int>(n,1));

        // Iterate to all cells and set dp[i][j] to sum of paths from previous cells
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // return Value of last grid
        return dp[m-1][n-1];
    }
};