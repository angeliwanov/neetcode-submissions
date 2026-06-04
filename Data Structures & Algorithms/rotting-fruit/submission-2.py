class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        queue = deque()
        rows = len(grid)
        cols = len(grid[0])
        fresh = 0

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    queue.append((row,col))
                elif grid[row][col] == 1:
                    fresh += 1
        
        minutes = 0
        while queue and fresh:
            length = len(queue)
            for _ in range(length):
                row, col = queue.popleft()

                for d_row, d_col in directions:
                    n_row = row + d_row
                    n_col = col + d_col
                    if 0 <= n_row < rows and 0 <= n_col < cols and grid[n_row][n_col] == 1:
                        grid[n_row][n_col] = 2
                        queue.append((n_row, n_col))
                        fresh -= 1
            minutes += 1

        return -1 if fresh else minutes
