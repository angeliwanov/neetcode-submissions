class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []

        def backtrack(row, diags, antidiags, cols, board):
            if row == n:
                res.append(["".join(r) for r in board])
                return
            
            for col in range(n):                     
                diag = row - col
                antidiag = row + col
                if col in cols or diag in diags or antidiag in antidiags:
                    continue
                board[row][col] = "Q"                    
                cols.add(col)
                diags.add(diag)
                antidiags.add(antidiag)                    
                backtrack(row+1, diags, antidiags, cols, board)                    
                antidiags.remove(antidiag)
                diags.remove(diag)
                cols.remove(col)                                     
                board[row][col] = "."
        
        board = [["."] * n for _ in range(n)]                
        backtrack(0, set(), set(), set(), board)

        return res