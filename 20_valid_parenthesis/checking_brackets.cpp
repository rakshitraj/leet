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
        for(char ch: s) {
            if (match.find(ch) != match.end()) {
                if ( opened.empty() || opened.top() != match[ch]) {
                    return false;
                }
                else {
                    opened.pop();
                } 
            }
            else {
                opened.push(ch);
            }
        }
        return opened.empty() ;
    }
};
