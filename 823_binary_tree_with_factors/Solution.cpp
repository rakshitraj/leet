#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int N = arr.size();
        int mod = 1000000007;
        std::sort(arr.begin(), arr.end());
        std::vector<long int> dp(N,1);
        std::unordered_map<int, int> indexOf;
        int i, j, right_node;

        for (i=0; i<N; i++){
            indexOf[arr[i]] = i;
        }

        for (i=0; i<N; i++){
            for (j=0; j<i; j++){
                if (arr[i]%arr[j] == 0){
                    right_node = arr[i]/arr[j];
                    if (indexOf.find(right_node)!=indexOf.end()){
                        dp[i] = (dp[i] + dp[j] * dp[indexOf[right_node]]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for(auto el: dp){
            ans += el;
        }
        return ans % mod;
    }
};

/**
class Solution {
public:
     int mod = pow(10,9) + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map <int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            long count = 1;
            for(auto j : rootWithCount){
                int rootEle = j.first;
                if(arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end()){
                    count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];  
                }
            }
            rootWithCount[arr[i]] = count;
        }
        int noOfTrees = 0;
        for(auto i : rootWithCount){
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        return noOfTrees;
    }
};
 */