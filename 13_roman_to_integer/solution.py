class Solution:
    def romanToInt (self, s: str) -> int:
        value = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        inverse_roman = s[::-1]
        prev = 0
        integer = 0
        for roman in inverse_roman:
            if value[roman] < prev:
                integer -= roman
            else:
                integer += value[roman]
            prev = value[roman]
        return integer