class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        rows = len(grid)
        cols = len(grid[0])
        def is_valid(r,c):
            return 0 <= r < rows and 0 <= c < cols and grid[r][c] == 1
        
        visited = set()        

        def dfs(r,c):            
            borders = 4
            for x, y in directions:
                nr, nc = r+x, c+y 
                if is_valid(nr,nc):                    
                    borders -= 1
                    if (nr,nc) not in visited:
                        visited.add((nr,nc))
                        borders += dfs(nr, nc)            
            return borders

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    visited.add((row,col))
                    return dfs(row, col)

            
        
        