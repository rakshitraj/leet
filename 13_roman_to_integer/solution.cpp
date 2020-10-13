#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> value = {
                                {'I',1},
                                {'V',5},
                                {'X',10},
                                {'L',50},
                                {'C',100},
                                {'D',500},
                                {'M',1000}
        };
    int prev = 0;
    int total = 0;

    for( int i = s.length() -1; i>= 0; --i) {
        char roman = s[i];
        
        if (value[roman] < prev) 
            total -= value[roman];
        else
        {
            total += value[roman];
        }

        prev = value[roman];
    }
    return total;
    }
};