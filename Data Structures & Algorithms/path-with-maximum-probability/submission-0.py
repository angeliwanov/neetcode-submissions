class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = defaultdict(list)
        for i in range(len(edges)):
            a = edges[i][0]
            b = edges[i][1]
            prob = succProb[i]
            graph[a].append((b,prob))
            graph[b].append((a,prob))
        
        maxHeap = []
        for neigh, prob in graph[start_node]:
            heapq.heappush(maxHeap, (-prob, neigh))
        visited = set()        

        max_prob = 0
        while maxHeap:
            prob, node = heapq.heappop(maxHeap)            
            visited.add(node)

            if node == end_node:
                max_prob = max(max_prob, -prob)
            
            for neigh, delta_prob in graph[node]:
                if neigh not in visited:            
                    heapq.heappush(maxHeap, (prob*delta_prob, neigh))
            
        return max_prob
