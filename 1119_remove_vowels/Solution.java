class Solution {
    public String removeVowels(String S) {
        Set<Character> set = new HashSet<>();

        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');

        StringBuilder sb = new StringBuilder();
        for (char c: S.toCharArray()){
            if (!set.contains(c))
                sb.append(c);
        }
        return sb.toString();
    }
}