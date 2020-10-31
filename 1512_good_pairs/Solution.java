import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numIdenticalPairs(int[] nums) {

        int goodPairs = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            if (freq.containsKey(nums[i])) {
                goodPairs = goodPairs + freq.get(nums[i]);
                freq.put(nums[i], freq.get(nums[i])+1);
            }
            else {
                freq.put(nums[i], 1);
            }
        }
        return goodPairs;
    }

    public static void main(String args[]){
        return;
    }
}