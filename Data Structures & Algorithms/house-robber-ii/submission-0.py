class Solution:
    def rob(self, nums: List[int]) -> int:     
        n = len(nums)        
        if n == 1:
            return nums[0]

        #take the first house
        dp = [0] * (n+1)               
        dp[1] = nums[0]
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])         

        #skip the first house
        dp2 = [0] * (n+1)
        for i in range(2, n+1):
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i-1])

        return max(dp[n-1], dp2[n])