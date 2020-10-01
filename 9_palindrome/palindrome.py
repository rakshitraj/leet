class Solution:
    def isPalindrome(self, x: int) -> bool:
        output = False
        
        if x < 0:
            return output
        
        cpy = str(x)
        rev = int(cpy[::-1])
        if x == rev:
            output = True
        return output