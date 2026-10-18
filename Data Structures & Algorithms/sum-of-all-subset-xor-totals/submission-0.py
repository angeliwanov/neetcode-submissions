class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def backtrack(subset, i):            
            if i == len(nums):
                return 0             
            
            total = 0
            
            for j in range(i, len(nums)):
                subset.append(nums[j])
                subXor = subset[0]                
                for k in range(1, len(subset)):
                    subXor ^= subset[k]                
                total += subXor + backtrack(subset, j+1)
                subset.pop()
            
            return total
        
        return backtrack([], 0)