class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows = len(board)
        cols = len(board[0])
        directions = [(0,1), (0,-1), (1,0), (-1,0)]        

        def backtrack(r,c,s,visited):            
            if len(s) == len(word):
                return "".join(s) == word
            
            for x,y in directions:
                nr, nc = r + x, c + y
                if nr >= 0 and nr < rows and nc >= 0 and nc < cols and (nr,nc) not in visited:
                    s.append(board[nr][nc])
                    visited.add((nr,nc))
                    if backtrack(nr,nc,s,visited):
                        return True
                    visited.remove((nr,nc))
                    s.pop()
        
        for r in range(rows):
            for c in range(cols):
                if backtrack(r,c,[board[r][c]],{(r,c)}):
                    return True
        return False