class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows = len(grid)
        cols = len(grid[0])    
        inf = 2147483647                                       
        q = deque()

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 0:
                    q.append((row,col))
        while q:                                                    
            length = len(q)
            for _ in range(length):
                r,c = q.popleft()
                for x,y in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nr, nc = r+x, c+y
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == inf:
                        grid[nr][nc] = 1 + grid[r][c]
                        q.append((nr,nc))                         
