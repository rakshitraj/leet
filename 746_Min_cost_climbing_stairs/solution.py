class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        top = len(cost)
        price = []

        price.append(cost[0])
        price.append(cost[1])

        for i in range(2, top):
            price.append((cost[i] + min(price[i-1], price[i-2])))

        return min(price[top-1], price[top-2])