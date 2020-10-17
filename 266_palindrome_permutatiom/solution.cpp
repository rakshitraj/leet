#include <iostream>
#include <map>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::map<char, int> freq;
        
        for (int i=0; i<s.length(); i++) {
            
            if (freq.find(s[i]) != freq.end()) {
                freq[s[i]] = (freq[s[i]] + 1) % 2;
            }
            else freq[s[i]] = 1;         
        }
        
        int pass = s.length()%2 ? 1: 0;
        for (auto element: freq){
            if (element.second) {
                if (pass == 0)
                    return false;
                pass--;
            }
        }
        return true;
    }
};