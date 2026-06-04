class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t rows = obstacleGrid.size();
        size_t cols = obstacleGrid[0].size();
        vector<vector<int>> dp (rows, vector<int> (cols));

        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = 0; col < cols; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                }
                else {
                    if (row == 0 && col == 0) {
                        dp[row][col] = 1;
                    } else if (row == 0) {
                        dp[row][col] = dp[row][col-1];
                    } else if (col == 0) {
                        dp[row][col] = dp[row-1][col];
                    } else {
                        dp[row][col] = dp[row-1][col] + dp[row][col-1];
                    }                    
                } 
            }
        }

        return dp[rows-1][cols-1];
    }
};