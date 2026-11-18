class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0] * (n+1) for _ in range(2)]

        #take the first house and skip the last
        dp[1][1] = nums[0]

        for i in range(2, n):
            dp[0][i] = max(dp[0][i-1], dp[0][i-2] + nums[i-1])
            dp[1][i] = max(dp[1][i-1], dp[1][i-2] + nums[i-1])

        #skip the first house and take the last
        dp[0][n] = max(dp[0][n-1], dp[0][n-2] + nums[n-1])
        return max(dp[0][n], dp[1][n-1])