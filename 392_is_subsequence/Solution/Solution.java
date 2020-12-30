import java.util.ArrayList;

class Solution {
    public boolean isSubsequence(String s, String t) {
        if (t.length() == 0) return (s.length() == 0);

        char[] tArr = t.toCharArray();
        ArrayList<String> dict = new ArrayList<String>();
        dict.add("");

        for(int i=0; i<tArr.length; i++) {
            String str = dict.get(i);
            }
        return false;
    }
}