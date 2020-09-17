class Solution:
    def twoSum(self, nums: List[int], target: int) -> List(int):
        dict = {}
        for i, e in eneumerate(nums):
            if target - e in dict:
                return [dict.get(target-e), i]
            dict[e] = i