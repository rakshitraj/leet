#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;

        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (int i=0; i < intervals.size()-1; i++){
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
        }
};