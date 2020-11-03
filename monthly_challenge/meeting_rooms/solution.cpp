#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            return a.front() < b.front();
        });

        for (int i=0; i < intervals.size()-1; i++) {
            if (intervals[i].back() > intervals[i+1].front())
                return false; 
        }
        return true;
    }
};