class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        minHeap = [(grid[0][0],0,0)]
        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        visited = set()
        time = 0

        while minHeap:
            w,x,y = heapq.heappop(minHeap)
            if (x,y) in visited:
                continue
            
            visited.add((x,y))
            time = max(w,time)

            if x == n - 1 and y == n - 1:
                return time

            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                if (nx,ny) not in visited and 0 <= nx < n and 0 <= ny < n:
                    heapq.heappush(minHeap, (grid[nx][ny], nx, ny))

        return -1