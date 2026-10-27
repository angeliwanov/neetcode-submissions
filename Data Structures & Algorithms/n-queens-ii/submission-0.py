class Solution:
    def totalNQueens(self, n: int) -> int:
        def backtrack(row, cols, diags, antidiags):
            if row == n:
                return 1
            
            solutions = 0

            for col in range(n):
                diag = row - col
                antidiag = row + col
                if col in cols or diag in diags or antidiag in antidiags:
                    continue
                cols.add(col)
                diags.add(diag)
                antidiags.add(antidiag)
                solutions += backtrack(row+1, cols, diags, antidiags)
                antidiags.remove(antidiag)
                diags.remove(diag)
                cols.remove(col)
            
            return solutions

        return backtrack(0, set(), set(), set())