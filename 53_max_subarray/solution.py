class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        currSum = nums[0]
        
        for i in range(1, len(nums)):
            current = nums[i]
            currSum = max(current, currSum + current)
            maxSum = max(currSum, maxSum)
        
        return maxSum