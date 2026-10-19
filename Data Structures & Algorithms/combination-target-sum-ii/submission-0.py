class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def dp(index: int, subset: List[int], currSum: int):            
            if currSum == 0:           
                res.append(subset[:])
                return            
            
            j = 0
            for i in range(index, len(candidates)):             
                if j > 0 and candidates[i] == candidates[i-1]:
                    continue
                if candidates[i] <= currSum:
                    subset.append(candidates[i])
                    dp(i+1, subset, currSum - candidates[i])
                    subset.pop()
                j += 1
        
        dp(0, [], target)
        return res