class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        memo = {}

        def dp(idx, total):
            if idx == n:
                return total == 0
            if (idx, total) in memo:
                return memo[(idx,total)]

            memo[(idx,total)] = dp(idx+1, total+nums[idx]) or dp(idx+1, total-nums[idx])
            return memo[(idx,total)]
            
        return dp(0,0)