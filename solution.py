class Solution:
    def isArmstrong(self, N: int) -> bool:
        
        count = 0;
        arms = 0;
        num = N;
        
        for digit in str(N):
            count += 1;
            
        for _ in range(count):
            digit = num%10
            arms += digit**count
            num = int(num/10)
            
        return N==arms