I will use function `check(p1, p2, p3, p4)`, which will check if we have a square with `p1--p2` being one diagonal and `p3--p4` being another diagonal. We need to check several properties to have square:



1. First of all, every square is parallelogram, so middle points of both diagonals should be the same, so if they are not, we return `False`.
2. Second, diagonals should have equal length.
3. So far, if we have previous two properties, we can have rectangle, not square, so we need to check that pairs of adjacent sides are equal.
4. Finally, we need to make sure, that our square is not empty, that is its side is not equal to `0`, or `p1` not equal to `p2`.



Now, we need to apply this function `3` times, because point `p1` must be in some diagonal and it has `3` different options how to choose second element for this diagonal:



1. `p1--p2` and other diagonal `p3--p4`
2. `p1--p3` and other diagonal `p2--p4`
3. `p1--p4` and other diagonal `p2--p3`



**Complexity** Time and space complexity is `O(1)`, however with quite big constant, around `54` arithmetical operations for time.



```python3
class Solution:
    def validSquare(self, p1, p2, p3, p4):
        def dist(p,q):
            return (p[0]-q[0])**2 + (p[1]-q[1])**2
        
        def check(p1,p2,p3,p4):
            if p1[0]+p2[0] != p3[0]+p4[0] or p1[1]+p2[1] != p3[1]+p4[1]: return False
            if dist(p1,p2) != dist(p3,p4) or dist(p1,p4) != dist(p2,p4): return False
            if p1 == p2: return False
            return True
        
        return check(p1,p2,p3,p4) or check(p1,p3,p2,p4) or check(p1,p4,p2,p3)
```