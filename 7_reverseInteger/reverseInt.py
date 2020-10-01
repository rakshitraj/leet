class Solution:
    def reverse(self, x: int) -> int:
        x = str(x)
        rev = int('-' + x[-1:0:-1]) if x[0] == '-' else int(x[::-1])

        if rev >= -2147483648 and rev<= 2147483647: return rev
        else: return 0