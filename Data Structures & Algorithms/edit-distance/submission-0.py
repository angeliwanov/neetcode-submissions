class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        w1_len = len(word1)
        w2_len = len(word2)
        dp = [[float('inf')] * (w2_len+1) for _ in range(w1_len+1)]
        
        for i in range(w1_len+1):
            dp[i][w2_len] = w1_len - i
        for j in range(w2_len+1):
            dp[w1_len][j] = w2_len - j

        for i in range(w1_len -1, -1, -1):
            for j in range(w2_len - 1, -1, -1):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])

        return dp[0][0]