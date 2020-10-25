import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        
        List<Boolean> checks = new List<Boolean>();

        for (int i=0; i<l.length; i++){
            int[] subArray = Arrays.copyOfRange(nums, l[i], r[i]);
            Arrays.sort(subArray);

        }   
    }
}