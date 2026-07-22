class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((v,w))
        
        minHeap = [(0,k)]
        visited = set()
        time = 0

        while minHeap:
            weight, node = heapq.heappop(minHeap)
            if node in visited:
                continue
            visited.add(node)
            time = weight

            for neighbor, delta_weight in edges[node]:
                if neighbor not in visited:
                    heapq.heappush(minHeap, (weight + delta_weight, neighbor))
        
        return time if len(visited) == n else -1