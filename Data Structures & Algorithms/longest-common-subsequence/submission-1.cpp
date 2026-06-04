class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t m = text1.size();
        size_t n = text2.size();
        vector<vector<int>> dp (m+1, vector<int> (n+1));
        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};