from collections import deque
class Solution:
    
    def is_matching(self, left: str, right: str) -> bool:
        return (left+right) in ['()', '{}', '[]']
    
    def isValid(self, s: str) -> bool:
        valid = False
        stk = deque()
        
        if len(s) == 1 :
            return valid
        
        for char in s:
            if char in '({[':
                stk.append(char)
                valid = False
                
            if char in ')}]':
                if len(stk):
                    if self.is_matching(stk[-1], char):
                        valid = True
                        stk.pop()
                    else:
                        return False
                else:
                    return False
        
        if len(stk):
            return False
        return valid