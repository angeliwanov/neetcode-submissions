class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int>(n));
        dp[0][0] = 1;

        for (size_t row = 0; row < m; ++row) {
            for (size_t col = 0; col < n; ++col) {
                if (row == 0 || col == 0) {
                    dp[row][col] = 1;
                } else {
                    dp[row][col] = dp[row-1][col] + dp[row][col-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
