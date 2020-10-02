from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
       match = {
           ')':'(',
           '}':'{',
           ']':'['
       }
       opened = []
       for i in range(len(s)):
            if match.get(s[i], False):
               if len(opened)==0 or opened.pop() != match[s[i]]:
                   return False
            else:
                opened.append(s[i])
        return len(opened)==0