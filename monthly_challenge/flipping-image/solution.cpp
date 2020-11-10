#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    void reverse(vector<vector<int>>& flipped){
        for (auto row: flipped){
            std::reverse(row.begin(), row.end());
        }
    }

    void invert(vector<vector<int>>& flipped){
        for (auto row: flipped){
            for (int i= 0; i<flipped.size(); i++){
                if (row[i] == 0) row[i] = 1;
                else row[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty()) return vector<vector<int>>{};

        vector<vector<int>> flipped;
        reverse(A);
        invert(A);
        return A;
    }
};