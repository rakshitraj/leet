#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        std::vector<bool> checks;
        std::vector<int> subarray;

        for(int i = 0; i < l.size(); i++) {

            subarray.clear();
            for (int j = l[i]; j<= r[i]; j++){
                subarray.push_back(nums[i]);
            }
            std::sort(subarray.begin(), subarray.end());

            if (subarray.size() <= 2){
                checks.push_back(true);
                continue;
            }
            int diff = subarray[1] - subarray[0];
            for(int k=1; k<subarray.size() -1; k++){
                if (subarray[k] + diff != subarray[k+1]){
                    checks.push_back(false);
                    break;
                }
            }
        }
        return checks;
    }
};

void test(Solution& obj){
    vector<int> nums = {4,6,5,9,3,7};
    vector<int> l = {0,0,2};
    vector<int> r = {2,3,5};
    auto checks = obj.checkArithmeticSubarrays(nums, l , r);
    cout << " [ ";
    for (auto el: checks){
        cout << el << ", ";
    }
}

int main(){
    Solution obj;
    test(obj);
    return 0;
}