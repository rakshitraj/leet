#include<iostream>
#include<map>
#include<stack>
#include<cassert>

using namespace std;

class Solution{
public:
    map<char, char> dict{ {']','['}, {'}','{'}, {')','('} };

    bool isValid(string s) {
        string v;
        for (auto &ch: s) {
            if (!v.empty() && dict[ch] == v.back())
                v.pop_back();
            else
            {
                v.push_back(ch);
            }
            return v.empty();   
        }
    }
};
