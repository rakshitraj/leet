class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right, longest = 0, 0, 0
        letters = []
        
        while right < len(s):
            char = s[right]
            
            if char not in letters:
                letters.append(char)
                right += 1
                longest = max(len(letters), longest)
            else:
                letters.pop(left)
                
        return longest
        