class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)>0:
            word = strs[0]
            for i in range(1, len(strs)):
                word = self.LCP(word, strs[i]) 
            return word
        else:
            return ''
    
    def LCP(self, s1, s2):
        prefix = ''
        for i, char in enumerate(s1):
            if i < len(s2):
                if char == s2[i] :
                    prefix += char
                else:
                    break
        return prefix