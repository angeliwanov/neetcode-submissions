class TrieNode:
    def __init__(self):
        self.children= {}
        self.word = ""

class Solution:
    def __init__(self):
        self.root = TrieNode()
    
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        rows = len(board)
        cols = len(board[0])
        
        def dfs(node, row, col, visited):
            chr = board[row][col]
            if chr not in node.children:
                return False
            node = node.children[chr]
            
            if node.word:                
                result.append(node.word)
                node.word = ""
            
            for x, y in [(0,1),(0,-1),(1,0),(-1,0)]:
                nr, nc = row + x, col + y
                if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in visited:
                    visited.add((nr,nc))
                    dfs(node, nr, nc, visited)
                    visited.remove((nr,nc))
        
        self.buildTrie(words)
        result = []             
        for row in range(rows):
            for col in range(cols):
                visited = set()
                visited.add((row,col))
                dfs(self.root, row, col, visited)
                visited.remove((row,col))
        return result
    
    def buildTrie(self, words):        
        for word in words:
            node = self.root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word
