#include <iostream>
#include <cassert>
#include <string>
#include <set>

using namespace std;

class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
       
        std::set<char> letters;
        int left =0, right =0;
        int longest = 0;

        while(right < s.length()) {
            while(!letters.insert(s[right]).second) {
                letters.erase(s[left]);
                left++;
            }
            if ((right-left+1) > longest) longest = right -left+1;
            right++;
        }
        return longest;
    }
};

void test(Solution obj) {
    // Test1
    string s1 = "abcabcbb";
    int ans1 = 3;
    int op1 = obj.lengthOfLongestSubstring(s1);
    assert(ans1 == op1);

    // Test2
    string s2 = "pwwkew";
    int ans2 = 3;
    int op2 = obj.lengthOfLongestSubstring(s2);
    assert(ans2 == op2);
}
int main() {
    Solution obj;
    test(obj);
    return 0;
}