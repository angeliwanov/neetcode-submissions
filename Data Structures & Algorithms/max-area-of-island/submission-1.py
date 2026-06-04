class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        rows = len(grid)
        cols = len(grid[0])
        max_area = 0

        def is_valid(row,col):
            return 0 <= row < rows and 0 <= col < cols and grid[row][col] == 1

        def dfs(row,col):
            area = 1
            for d_row, y_col in directions:
                n_row = row + d_row
                n_col = col + y_col
                if is_valid(n_row, n_col):
                    grid[n_row][n_col] = 0
                    area += dfs(n_row,n_col)            
            return area


        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    grid[row][col] = 0
                    max_area = max(max_area, dfs(row, col))
            
        return max_area