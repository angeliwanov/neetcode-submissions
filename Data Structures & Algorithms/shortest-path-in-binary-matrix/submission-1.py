class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        directions = [[0,1],[0,-1],[1,0],[-1,0],[1,1],[-1,-1],[1,-1],[-1,1]]
        rows = len(grid)
        cols = len(grid[0])
        if grid[0][0] == 1 or grid[rows-1][cols-1] == 1:
            return -1
        
        def is_valid(row, col):
            return 0 <= row < rows and 0 <= col < cols and grid[row][col] == 0
        
        
        queue = deque([(0,0)])
        grid[0][0] = 1

        path = 0
        while queue:
            path += 1
            length = len(queue)

            for _ in range(length):
                row, col = queue.popleft()
                if row == rows - 1 and col == cols - 1:
                    return path

                for d_row, d_col in directions:
                    n_row = row + d_row
                    n_col = col + d_col
                    if is_valid(n_row, n_col):
                        grid[n_row][n_col] = 1
                        queue.append((n_row,n_col))

        return -1

