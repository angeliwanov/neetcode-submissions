class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        len1, len2 = len(s1), len(s2)
        if len1 + len2 != len(s3):
            return False

        dp = [[False] * (len2 + 1) for i in range(len1 + 1)]
        dp[len1][len2] = True

        for i in range(len1, -1, -1):
            for j in range(len2, -1, -1):
                if i < len1 and s1[i] == s3[i + j] and dp[i + 1][j]:
                    dp[i][j] = True
                if j < len2 and s2[j] == s3[i + j] and dp[i][j + 1]:
                    dp[i][j] = True
        return dp[0][0]