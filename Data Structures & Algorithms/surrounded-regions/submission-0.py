class Solution:
    def solve(self, board: List[List[str]]) -> None:
        rows = len(board)
        cols = len(board[0])
        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        visited = set()

        def dfs(r,c):
            visited.add((r,c))
            for x,y in directions:
                nr, nc = r+x, c+y
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == "O" and (nr,nc) not in visited:
                    dfs(nr,nc)       

        for row in [0,rows-1]:
            for col in range(cols): 
                if board[row][col] == "O" and (row,col) not in visited:                    
                    dfs(row,col)
                    
        for row in range(rows):
            for col in [0,cols-1]: 
                if board[row][col] == "O" and (row,col) not in visited:                    
                    dfs(row,col)
        
        for row in range(1, rows-1):
            for col in range(1, cols-1):
                if board[row][col] == "O" and (row,col) not in visited:                       
                   board[row][col] = "X"