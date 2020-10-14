class Solution {
    public boolean isArmstrong(int N) {
        
        int digit, count=0, arms =0, num = N;
        
        while (num > 0) {
            count++;
            num/=10;
        }
        num=N;
        
        while (num > 0) {
            digit = num%10;
            arms += Math.pow(digit, count);
            num /= 10;
        }
        
        return (arms==N);
    }
}