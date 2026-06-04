class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:        
        directions = [[0,1], [0,-1], [1,0], [-1,0]]
        rows = len(image)
        cols = len(image[0])
        start = image[sr][sc]        

        def dfs(row, col):
            for x, y in directions:
                nr = row + x
                nc = col + y
                if 0 <= nr < rows and 0 <= nc < cols and image[nr][nc] == start:
                    image[nr][nc] = color
                    dfs(nr, nc)

        if image[sr][sc] != color:           
            image[sr][sc] = color
            dfs(sr, sc)
        
        return image
        