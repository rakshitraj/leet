#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        
        std::vector<std::vector<int>> result;

        for (auto el: intervals) {
            if (el[1] <= toBeRemoved[0] || el[0] >= toBeRemoved[1]) {
                result.push_back(el);
            }
            else if (el[0] >= toBeRemoved[0] && el[1] <= toBeRemoved[1]){
                continue;
            }
            else {
                if (el[0] < toBeRemoved[0] && el[1] >= toBeRemoved[1]) {
                    result.push_back(std::vector<int>{el[0], toBeRemoved[0]});
                    result.push_back(std::vector<int>{toBeRemoved[1], el[1]});
                }
                else if (el[0] < toBeRemoved[0] && el[1] < toBeRemoved[1]) {
                    result.push_back(std::vector<int>{el[0], toBeRemoved[0]});
                }
                else result.push_back(std::vector<int>{toBeRemoved[1], el[1]});
            }
        }
        return result;
    }
};