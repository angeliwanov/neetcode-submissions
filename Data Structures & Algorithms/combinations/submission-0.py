class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def backtrack(comb, index):
            if len(comb) == k:
                res.append(comb[:])
                return
            
            for i in range(index, n+1):
                comb.append(i)
                backtrack(comb, i+1)
                comb.pop()
            
        backtrack([], 1)
        return res