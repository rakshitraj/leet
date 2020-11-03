import java.util.List;

class Solution {
    public int maxPower(String s) {
        
        List<Integer> letters = new ArrayList<Integer>();
        char[] input = s.toCharArray();

        letters.add(1);

        for (int i =1; i<input.length; i++){
            if (input[i] == input[i-1]){
                letters.add(letters.get(i-1) + 1);
            }
            else {
                letters.add(1);
            }
        }
        
        int max=0;
        for (int el: letters){
            if (el > max)
                max = el;
        }
        return max; 
    }
}