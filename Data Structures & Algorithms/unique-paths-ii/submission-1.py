class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])
        dp = [[0] * (cols) for _ in range(rows)]

        for row in range(rows):
            for col in range(cols):
                if obstacleGrid[row][col] == 1:
                    dp[row][col] = 0
                else:
                    if row == 0 and col == 0:
                        dp[row][col] = 1
                    elif row == 0:
                        dp[row][col] = dp[row][col-1]
                    elif col == 0:
                        dp[row][col] = dp[row-1][col]
                    else:
                        dp[row][col] = dp[row-1][col] + dp[row][col-1]
        
        return dp[rows-1][cols-1]