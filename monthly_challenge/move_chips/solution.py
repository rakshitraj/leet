class Solution:
    def minCostToMoveChips(self, position: list[int]) -> int:
        
        dict = {}
        
        for destination in position:
            if not dict.get(destination):
                cost = 0
                for pos in position:
                    cost += abs(pos - destination)%2
                dict[destination] = cost
                
        minCost = float("inf")
        for (pos, cost) in dict.items():
            if cost < minCost:
                minCost = cost
                
        return minCost