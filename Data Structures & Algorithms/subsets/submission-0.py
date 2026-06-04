class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:        
        result = []
        
        def backtrack(subset, index):
            result.append(subset[:])            
                            
            for i in range(index, len(nums)):            
                subset.append(nums[i])                
                backtrack(subset, i+1)
                subset.pop()
        
        backtrack([], 0)
        return result

0 
1 