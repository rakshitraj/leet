#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty()) return vector<vector<int>>{};

        vector<vector<int>> flipped(A.size());
        for (int i=0; i<A.size(); i++) {
            for (int j=A[i].size()-1; j>=0; j--) {
                flipped[i].push_back((A[i][j] == 0 ? 1 : 0));
            }
        }
        return flipped;
    }
};