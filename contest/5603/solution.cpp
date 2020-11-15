#include <iostream>
#include <cstring>
#include <set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        std::set<char> w1;
        std::set<char> w2;
        
        for (char ch: word1){
            w1.insert(ch);
        }
        for (char ch: word2) {
            w2.insert(ch);
        }

        if (w1.size() != w2.size()) return false;

        std::set<char>::iterator it1 = w1.begin();
        std::set<char>::iterator it2 = w2.begin();

        while(it1 != w1.end()){
            if (*it1 != *it2) return false;
        }
        return true;
    }
};