class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digits = []
        letters = []

        for log in logs:
            log_split = log.split(' ', maxsplit=1)
            if log_split[1][0].isdigit():
                digits.append(log)
            else:
                letters.append([''.join(log_split[1]), log_split[0]])
        letters.sort()
        return [j+' '+i for i,j in letters] + digits