class Solution {
    public String removeVowels(String S) {
        
        char[] str = S.toCharArray();
        String output = "";
        
        for (int i=0; i<str.length; i++){
            char ch = str[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
            output += ch;
        }
        return output;
    }
}