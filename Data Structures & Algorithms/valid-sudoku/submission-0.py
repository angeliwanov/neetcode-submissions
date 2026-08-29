class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = len(board)
        cols = len(board)
        r = defaultdict(set)
        c = defaultdict(set)
        b = defaultdict(set)

        for row in range(rows):            
            for col in range(cols):
                digit = board[row][col]
                if digit == '.':
                    continue
                box = (row//3)*10 + col//3
                if digit in r[row] or digit in c[col] or digit in b[box]:
                    return False
                r[row].add(digit)
                c[col].add(digit)
                b[box].add(digit)                
        
        return True
            
        
