#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    const int shift = 15; // max size of n is 20,000, so we can use 32768 to pack info above edge info
    const int cntr = 1 << shift;
    const int mask = cntr - 1;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        //if (n==2) return {0,1};
        
        edges.push_back(vector<int>{0,0});
        const int k2 = n - 1;
        for (int k=0; k < k2; k++) {
            int i = edges[k][0] & mask;
            int j = edges[k][1] & mask;
            edges[i][0] += cntr; // counts
            edges[i][1] += (j << shift); // sums

            edges[j][0] += cntr;
            edges[j][1] += (i << shift);
        }

        deque<int> leaves;
        const int m = n;
        for (int i=0; i < m; i++) {
            edges[i][0] = edges[i][0] >> shift;
            edges[i][1] = edges[i][1] >> shift;
            if (edges[i][0]==1) leaves.push_back(i);
        }
        
        while (n > 2) {
            const int leaves_size = leaves.size();
            for (int i=0; i < leaves_size; i++) {
                const int leaf = leaves.front(); leaves.pop_front();
                const int conn = edges[leaf][1];
                edges[conn][1] -= leaf;
                if (--edges[conn][0]==1) leaves.push_back(conn);
            }
            n -= leaves_size;
        }

        return vector<int>(leaves.begin(), leaves.end());
    }
};