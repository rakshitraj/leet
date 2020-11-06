import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Solution {
    public int smallestDivisor(int[] nums, int threshold) {

        HashMap<Integer, Integer> divisor = new HashMap<>();
        
        int prev = 1;
        int curr = 1;
        
        while(true) {
            int sum = 0;
            if (divisor.get(curr) == null){
                for (int i=0; i<nums.length; i++){
                    sum += Math.ceil((double)nums[i]/curr);
                    if (sum >= threshold) break;
                }
                divisor.put(curr, sum);
            }
            else sum = divisor.get(curr);
            //System.out.println(prev + " .. " + curr);
            if (sum >= threshold){
                prev = curr;
                curr = 2*curr;
                //System.out.println(prev + " " + curr);
            }
            else {
                if((prev + curr)/2 == prev) break;
                curr = (prev+curr)/2;
                //System.out.println(prev + " " + curr);
                }
        }
        Iterator it = divisor.entrySet().iterator();
        Map.Entry maxima = null; 
        int max = 0;
        while(it.hasNext()){
            Map.Entry obj = (Map.Entry)it.next();
            if ((int)obj.getValue() > max && (int)obj.getValue() <= threshold){
                max = (int)obj.getValue();
                maxima = obj;
            }
        }
        return maxima != null? (int)maxima.getKey(): 0;
    }
}