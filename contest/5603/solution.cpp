#include <iostream>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if (word1.length() != word2.length()) return false;
        
        std::unordered_set<char> w1;
        std::unordered_set<char> w2;
        std::vector<int> one(26, 0);
        std::vector<int> two(26, 0);

        one.resize(26);

               
        for (char ch: word1){
            w1.insert(ch);
            one[(int)ch - 97]++;
        }
        std::sort(one.begin(), two.begin());

        for (char ch: word2) {
            if (w1.insert(ch).second) return false;
            w2.insert(ch);
            two[(int)ch - 97]++;
        }
        std::sort(two.begin(), two.begin());
        
        if(w1.size() != w2.size()) return false;

        for (int i=0; i<26; i++) {
            if (one[i] != two[i]) return false;
        }
        
        return true;
    }
};