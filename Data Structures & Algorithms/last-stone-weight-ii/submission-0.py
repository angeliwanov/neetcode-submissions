class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:        
        stoneTotal = sum(stones)
        target = stoneTotal // 2
        n = len(stones)

        dp = [[0] * (target+1) for _ in range(n+1)]

        for i in range(1, n+1):
            for j in range(target+1):
                if stones[i-1] <= j:
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1])
                else:
                    dp[i][j] = dp[i-1][j]
        
        return stoneTotal - 2 * dp[n][target]

        