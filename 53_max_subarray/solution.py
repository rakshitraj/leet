class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = []
        currMaxSum = []
        
        #Base Case
        max = nums[0]
        maxSum.append(max)
        currMaxSum.append(max)
        
        for i in range(1, len(nums)):
            current = nums[i]
            
            if current + currMaxSum[i-1] > current:
                currMaxSum.append(current + currMaxSum[i-1])
            else:
                currMaxSum.append(current)
                
            if currMaxSum[i] > max:
                max = currMaxSum[i]
            maxSum.append(max)
            
        return maxSum[-1]