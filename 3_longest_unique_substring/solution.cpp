#include <iostream>
#include <cassert>
#include <cstring>
#include <set>

using namespace std;

class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
       
       bool unique_char[256];
       std::memset(unique_char, false, sizeof(unique_char));
       int left, right;
       int max_len = 0, curr_len = 0;
       left = 0;
       right = 0;

       while(right < s.length()) {
           if (unique_char[s[right]]) {
               unique_char[s[left]] = false;
               left++;
           }
           else
           {
               unique_char[s[right]] = true;
               curr_len = right - left +1;
               max_len = std::max(max_len, curr_len);
               right ++;
           }
       }
       return max_len;
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