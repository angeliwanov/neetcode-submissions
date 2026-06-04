class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        visited = set()
        rows = len(grid)
        cols = len(grid[0])
        directions = [[0,1],[0,-1],[1,0],[-1,0]]

        def is_valid(row,col):
            return 0 <= row < rows and 0 <= col < cols and grid[row][col] == '1' and (row, col) not in visited
        
        for row in range(rows):
            for col in range(cols):
                if is_valid(row, col):
                    islands +=1
                    visited.add((row,col))
                    stack = [(row, col)]
                    while stack:
                        r,c = stack.pop()
                        for x,y in directions:
                            nr = r+x
                            nc = c+y
                            if is_valid(nr,nc):
                                visited.add((nr,nc))
                                stack.append((nr,nc))

        return islands