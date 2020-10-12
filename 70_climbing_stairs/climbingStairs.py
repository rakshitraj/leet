class Solution:
    def climbStairs(self, n: int) -> int:
        #Base case
        ways = [0, 1, 2]
        for i in range(3, n+1):
            ways.append(ways[i-1] + ways[i-2]) 
        return ways[n]