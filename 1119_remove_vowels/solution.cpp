#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string removeVowels(string S) {
        std::set<char> chars;
        std::string output;

        chars.insert('a');
        chars.insert('e');
        chars.insert('i');
        chars.insert('o');
        chars.insert('u');

        for (int i=0; i<S.length(); i++){
            if (chars.find(S[i]) == chars.end())
                output += S[i];
        }
        return output;
    }
};