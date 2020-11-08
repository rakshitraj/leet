#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        
        std::sort(A.begin(), A.end());
        int front = 0, back = A.size() -1;
        int maxSum = -1, sum = 0;
        while (front < back){
            sum = A[front] + A[back];
            if (sum >= K){
                back--;
            }
            else {
                front++;
                maxSum = sum>maxSum? sum : maxSum ;
            }
        }
        return maxSum;
    }
};