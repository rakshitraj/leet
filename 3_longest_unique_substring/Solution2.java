public class Solution2 {
    public int lengthOfLongestSubstring(String s) {
        
        if (s == null || s.length() == 0) return 0;
        char[] charArray = s.toCharArray();
        int start = 0;
        int length = 1, longest = 1;
        
        for (int i=1; i<s.length(); ++i) {
            for (int j=start; j<i; j++) {
                if (charArray[i] == charArray[j]){
                    start = j+1;
                    break;
                }
            }
            length = i - start + 1;
            longest = Math.max(longest, length);
        }
        return longest;
    }
}
