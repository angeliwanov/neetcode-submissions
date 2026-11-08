class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows = len(heights)
        cols = len(heights[0])

        def dfs(r,c,visited):
            ocean = 0
            if r == 0 or c == 0:
                ocean |= 1
            if r == rows - 1 or c == cols -1:
                ocean |= 2
            
            for x,y in [(0,1),(0,-1),(1,0),(-1,0)]:
                nr, nc = r+x, c+y
                if nr >= 0 and nr < rows and nc >= 0 and nc < cols and heights[nr][nc] <= heights[r][c] and (nr,nc) not in visited:
                    visited.add((nr,nc))
                    ocean |= dfs(nr,nc,visited)

            return ocean
        
        res = []
        for r in range(rows):
            for c in range(cols):
                if dfs(r,c,{(r,c)}) == 3:
                    res.append([r,c])
        return res
