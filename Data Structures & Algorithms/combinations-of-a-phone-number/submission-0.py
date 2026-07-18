class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        digToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        result = []
        if not digits:
            return result
            
        def backtrack(comb, digit):
            if digit == len(digits):
                result.append(''.join(comb[:]))
                return
            
            for letter in digToChar[digits[digit]]:
                comb.append(letter)
                backtrack(comb, digit+1)
                comb.pop()

        backtrack([], 0)
        return result