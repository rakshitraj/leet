#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max_pow = 0, pow = 1;
        char prev = ' ';
        
        for (auto c : s){
            if (c==prev)
                pow++;
            else
                pow = 1;
            
            if (pow > max_pow)
                max_pow = pow;
            
            prev = c;
        }
        return max_pow;
    }
};