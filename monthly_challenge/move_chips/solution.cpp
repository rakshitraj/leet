#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        std::map<int, int> costs;
        int minCost = INT32_MAX;

        for(int destination: position){
            if (costs.find(destination) == costs.end())
            {
                int cost = 0;
                for (int i=0; i<position.size(); i++){
                    cost += abs(position[i] - destination)%2;
                }
                costs.insert(std::make_pair(destination, cost));
            }
            if (costs[destination] < minCost){
                minCost = costs[destination];
            }
        }
        return minCost;
    }
};