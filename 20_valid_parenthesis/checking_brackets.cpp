#include<iostream>
#include<unordered_map>
#include<stack>
#include<cassert>

using namespace std;

class Solution{
public:
     bool isValid(string s) {
        std::unordered_map<char, char> match = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        std::stack<char> opened;
        for (int i=0; i<s.length(); i++) {
            if (match.find(s[i]) != match.end())
                if ( opened.size()==0 || opened.top() != match[s[i]])
                    return false;
                else
                    opened.pop();
            else
                opened.push(s[i]);
        }
        return opened.size()==0 ;
    }
};
