from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
       match = {
           ')':'(',
           '}':'{',
           ']':'['
       }
       opened = []
       for char in s:
            if match.get(char, False):
               if len(opened)==0 or opened.pop() != match[char]:
                   return False
            else:
                opened.append(char)
        return len(opened)==0