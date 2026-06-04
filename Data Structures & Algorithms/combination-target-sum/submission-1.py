class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        def backtrack(target, index, subset):
            if target == 0:
                result.append(subset[:])
            
            for i in range(index, n):
                if nums[i] <= target:
                    subset.append(nums[i])
                    backtrack(target-nums[i], i, subset)
                    subset.pop()

        
        result = []
        n = len(nums)
        backtrack(target, 0, [])
        return result

