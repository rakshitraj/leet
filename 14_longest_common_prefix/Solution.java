class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length > 0) {
            String word = strs[0];
            for (int i = 1; i<strs.length; i++){
                word = LCP(word, strs[i]);
            }
            return word;
        }
        else {
            return "";
        }
    }

    public String LCP(String first, String second) {
        String prefix = "";
        for (int i=0; i < first.length(); i++){
            if (i < second.length()) {
                if (first.charAt(i) == second.charAt(i)) {
                    prefix += first.charAt(i);
                    continue;
                }
                break;
            }
            break;
        }
        return prefix;
    }
}