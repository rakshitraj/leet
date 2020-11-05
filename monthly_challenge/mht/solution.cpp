#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
private:
int traverse_mht(int root, vector<vector<int>>& am, vector<bool> visited){
    int height = 0;
    stack<int> stk;
    stk.push(root);
    visited[root] = true;

    while(!stk.empty()){
        int root = stk.top();
        stk.pop();

        int prev_stk = stk.size();
        for (int i=0; i<am[root].size(); i++){
            if (visited[am[root][i]] == false){
                stk.push(am[root][i]);
            }
        }
        if (prev_stk != stk.size()){
            height++;
        }
    }
    return height;
}

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (edges.empty()) return vector<int>{};

    std::map<int, vector<int>> mht;
    for (int i=0; i<=n; i++){
        mht[i]=vector<int>({});
    }

    // Adjacency matrix
    vector<vector<int>> am;
    am.resize(n);
    for (int i=0; i<edges.size(); i++){
        int x = edges[i][0];
        int y = edges[i][1];
        am[x].push_back(y);
        am[y].push_back(x);
    }

    for (int root = 0; root < n; root++){
        vector<bool> visited(n, false);
        mht.at(traverse_mht(root, am, visited)).push_back(root);
    }
    
    for (auto &el: mht){
        if (!el.second.empty())
            return el.second;
    }
    return vector<int>{};
    }
};