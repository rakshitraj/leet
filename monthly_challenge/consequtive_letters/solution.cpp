#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        std::vector<int> power;
        power.push_back(1);
        int max = 0;

        for (int i=1; i<s.length(); i++) {
            if (s[i-1] == s[i])
                power.push_back(power.back() + 1);
            else power.push_back(1);
            max = std::max(max, power.back());
        }
        return max;
    }
};