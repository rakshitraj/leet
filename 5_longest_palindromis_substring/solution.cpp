
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

// Manacher's algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        
        // Using bogus character #
        std::vector<char> str = {'#'};
        str.reserve(2*s.length());

        int longest = 1; 
        int center = 0;

        for (int i=0; i<s.length(); ++i)  {
            str.push_back(s[i]);
            str.push_back('#');
        }

        for (int i=0; i < str.size(); i++) {
            
            int left = i-1;
            int right = i+1;
            int len = 0;
            
            while(left >= 0 && right < str.size() && str[left] == str[right]) {
                left--;
                right++;
            }
            len = right - left + 1;
            if (len > longest) {
                longest = len;
                center = i;
            }
        }
        int start = center - ((longest - 1)/2) + 1;
        int end = center + ((longest - 1)/2) - 1;

        string output = "";
        for (int i = start; i < end; i++) {
            if (str[i] != '#') output += str[i];
        }

        str.empty();

        return output;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        int curL = 0, curR = 0;
        int cur = 0, n = s.size();
        while (cur < n)
        {
            left = cur;
            right = cur;
            for(; right<n-1 && s[right] == s[right+1]; right++);
            cur = right+1;
            for(; left>0 && right<n-1 && s[left-1] == s[right+1]; left--, right++);
            
            if(right-left > curR-curL)
            {
                curL = left;
                curR = right;
            }
        }
        return s.substr(curL, curR-curL+1);
    }
};

// speed 2>1>3
class Solution3 {
private:
    int palength(string s, int left, int right) {
        int len = 0;
        while (left >= 0  && right < s.length() && s[left] == s[right]) {
            len = right-left+1;
            left--;
            right++;
        }
        return len;
    }
public:
    string longestPalindrome(string s) {
        int longest = 1;
        int start = 0, end =0;
        for(int i=1; i<s.length(); i++) {
            int len1 = palength(s, i, i); /* racecar */
            int len2 = palength(s, i, i+1); /* abba */
            int len = std::max(len1, len2);
            if (len > longest) {
                longest = len;
                start = i - ((len-1)/2);
        }
        return s.substr(start, longest);
    }
}
};

void test(Solution obj) {
    // Test1
    string s1 = "abababbaba";
    string p1 = "ababbaba";
    string op1 = obj.longestPalindrome(s1);
    std::cout << s1 << " : " << op1 << std::endl;
    assert(p1 == op1);

    // Test 2
    string s2 = "racecarac";
    string p2 = "racecar";
    string op2 = obj.longestPalindrome(s2);
    std::cout << s2 << " : " << op2  << std::endl;
    assert(p2 == op2);
}


int main()
{
    Solution obj;
    std::cout << "\n";
    test(obj);
    return 0;
}