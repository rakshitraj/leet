class Solution {

    public String findPrefix(String[] strs, int left, int right) {
        
        String s = "";
        char[] S1;
        char[] S2;
        
        if (left == right) return strs[left];
        if (left > right) return s;
        
        if (right - left > 1) {
            int mid = (left+right)/2;
            S1 = findPrefix(strs, left, mid).toCharArray();
            S1 = findPrefix(strs, mid+1, right).toCharArray();
        }
        else {
            S1 = strs[left].toCharArray();
            S2 = strs[right].toCharArray();
        }

        int i = (S1.length < S2.length ) ? S1.length: S2.length;
        while (S1[i] == S2[i])
            s += S1[i++];

        return s;

    }

    public String longestCommonPrefix(String[] strs) {

        return findPrefix(strs, 0, strs.length - 1);
    }
}