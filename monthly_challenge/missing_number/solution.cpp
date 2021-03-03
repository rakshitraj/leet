#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums){
        
        // de-sync standard streams
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(false);

        // solution
        int n = nums.size();
        int total = ((n+1)*n)/2;
        int sum = 0;
        for (int el: nums){
            sum += el;
        }
        return total-sum;
    }
};