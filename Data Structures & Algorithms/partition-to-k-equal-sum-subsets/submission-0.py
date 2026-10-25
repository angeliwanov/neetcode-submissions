class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:   
        nums.sort(reverse=True)     
        total = sum(nums)
        if total % k != 0:
            return False
        target = total // k
        if max(nums) > target:
            return False        
        
        def backtrack(index, subsets):                        
            if index == len(nums):
                return sum(subsets) == total
            
            for i in range(index, len(nums)): 
                if i > index and nums[i] == nums[i-1]:
                    continue            
                for j in range(k):
                    if j > 0 and subsets[j] == subsets[j-1]:
                        continue
                    if subsets[j] + nums[i] <= target:
                        subsets[j] += nums[i]
                        if backtrack(i+1, subsets):
                            return True
                        subsets[j] -= nums[i]
            return False
        
        return backtrack(0, [0] * k)
        