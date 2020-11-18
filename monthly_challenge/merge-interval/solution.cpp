#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() == 0) return vector<vector<int>>{};
        
        std::sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i=1; i<intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]){
                auto back = res.back();
                res.pop_back();
                res.push_back(vector<int>{std::min(back[0], intervals[i][0]), std::max(back[1], intervals[i][1])});
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};