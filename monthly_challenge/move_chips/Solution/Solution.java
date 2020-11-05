import java.util.HashMap;

class Solution {
    public int minCostToMoveChips(int[] position) {
        HashMap<Integer, Integer> costs = new HashMap<>();
        int minCost = Integer.MAX_VALUE;
        for (int i =0; i<position.length; i++){
            if (costs.get(position[i]) == null){
                int cost = 0;
                for (int pos=0; pos < position.length; pos++) {
                    cost += Math.abs(position[pos] - position[i])%2;
                }
                costs.put(position[i], cost);
            }
            if (costs.get(position[i]) < minCost){
                minCost = costs.get(position[i]);
            }
        }
        return minCost;
    }
}