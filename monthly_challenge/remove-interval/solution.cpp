#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        
        std::vector<std::vector<int>> result;

        for (auto el: intervals) {

            if (el[1] <= toBeRemoved[0]){
                result.push_back(el);
            }
            else if (el[0] >= toBeRemoved[1]) {
                result.push_back(el);
            }
            else if(el[0] > toBeRemoved[0] && el[1] <= toBeRemoved[1]) continue;
            else {
                int start, end;
                if (el[1] < toBeRemoved[1]) {
                    start = el[0];
                    end = toBeRemoved[0];
                }
                else {
                    start = toBeRemoved[1];
                    end = el[1];
                }
                result.push_back(std::vector<int>{start, end});
            }
        }
        return result;
    }
};