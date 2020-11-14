class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:

        enigma = [0] * len(code)

        if k == 0 : return enigma

        for i in range(len(code)) :
            count = k
            sum = 0

            if k > 0 :
                while(count):
                    index = i + count
                    if index > len(code):
                        index = len(code) - index
                    sum += code[index]
                    count = count - 1

            else :
                while(count):
                    index = i + count
                    if index < 0:
                        index = len(code) + index
                    sum += code[index]
                    count = count + 1

            enigma[i] = sum

        return enigma
