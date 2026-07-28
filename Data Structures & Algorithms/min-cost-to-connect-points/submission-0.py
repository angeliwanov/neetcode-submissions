class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        graph = defaultdict(list)
        for i in range(0,n-1):
            xi, yi = points[i]
            for j in range(i+1, n):
                xj, yj = points[j]
                dist = abs(xi-xj) + abs(yi-yj)
                graph[i].append([j,dist])
                graph[j].append([i,dist])
            
        minHeap = [(0,0)]
        visited = set()
        cost = 0

        while len(visited) < n:
            dist,node = heapq.heappop(minHeap)
            
            if node in visited:
                continue
            visited.add(node)
            cost += dist

            for nei, wei in graph[node]:
                if nei not in visited:
                    heapq.heappush(minHeap, (wei,nei))

        return cost
