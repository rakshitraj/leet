#include <iostream>

class Solution {
    public:
    int climbStairs (int n) {
        long long int a=1, b=1, temp=0;
        for (int i=0; i<n; i++) {
            temp = a;
            a = b;
            b = temp+b;
        }
        return a;
    }
};