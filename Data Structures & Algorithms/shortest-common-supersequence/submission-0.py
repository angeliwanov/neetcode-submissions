class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)
        dp = [[""] * (len2+1) for _ in range(len1+1)]

        for i in range(len1+1):
            for j in range(len2+1):
                if i == 0:
                    dp[i][j] = str2[:j]
                elif j == 0:
                    dp[i][j] = str1[:i]
                elif str1[i-1] == str2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + str1[i-1]
                else:
                    if len(dp[i-1][j]) < len(dp[i][j-1]):
                        dp[i][j] = dp[i-1][j] + str1[i-1]
                    else:
                        dp[i][j] = dp[i][j-1] + str2[j-1]
            
        return dp[len1][len2]