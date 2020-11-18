#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i, n = intervals.size();
        vector<pair<int, int>> v;
        for(i=0;i<n;i++){
            v.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        sort(v.begin(), v.end());
        if(n == 0){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        int start = v[0].first;
        int end = v[0].second;
        for(i=1;i<n;i++){
            if(end >= v[i].first){
                end = max(end, v[i].second);
            }else{
                vector<int> interval;
                interval.push_back(start);
                interval.push_back(end);
                ans.push_back(interval);
                start = v[i].first;
                end = v[i].second;
            }
        }
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        ans.push_back(interval);
        return ans;
    }
};