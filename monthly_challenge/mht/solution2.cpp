#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 1. Create list of adjacencies for each node (nodeAdjs)
    // 2. Get nodes which are leaves
    // 3. Remove leaf nodes from nodeAdjs
    // 4. Repeat 2 and 3 until we have 1 or 2 nodes left
    // 5. Return nodes left
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        
        unordered_map<int, unordered_set<int>> nodeAdjs;
        vector<int> leaves;
        
        buildNodeAdjacencies(nodeAdjs, edges);
        
        while (nodeAdjs.size() > 2) {
            getLeaves(leaves, nodeAdjs);
            removeNodes(nodeAdjs, leaves);
        }
        
        getLeaves(leaves, nodeAdjs);
            
        return leaves;
    }
    
private:
    void buildNodeAdjacencies(unordered_map<int, unordered_set<int>>& nodeAdjs, const vector<vector<int>>& edges) const {
        nodeAdjs = unordered_map<int, unordered_set<int>>(edges.size() + 1);
        for (const auto& edge : edges) {
            nodeAdjs[edge[0]].insert(edge[1]);
            nodeAdjs[edge[1]].insert(edge[0]);
        }
    }
    
    void getLeaves(vector<int>& leaves, const unordered_map<int, unordered_set<int>>& nodeAdjs) const {
        leaves = vector<int>();
        for (const auto& p : nodeAdjs) {
            if (p.second.size() <= 1) {
                leaves.push_back(p.first);
            }
        }
    }
    
    void removeNodes(unordered_map<int, unordered_set<int>>& nodeAdjs, const vector<int>& nodes) const {
        for (const auto& node : nodes) {
            for (const auto& adj : nodeAdjs[node]) {
                nodeAdjs[adj].erase(node);
            }
            nodeAdjs.erase(node);
        }
    }
};