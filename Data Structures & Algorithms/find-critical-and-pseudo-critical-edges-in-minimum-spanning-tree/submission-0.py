class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(list)
        for idx, edge in enumerate(edges):
            graph[edge[0]].append((edge[1],edge[2],idx))
            graph[edge[1]].append((edge[0],edge[2],idx))
        
        def mst(src, dst, index):     
            dist = [float('inf')] * n                    
            minHeap = [(0,src)]            
            dist[src] = 0

            while minHeap:                
                weight, node = heapq.heappop(minHeap)
                if node == dst:
                    return weight                                     

                for nei, wei, idx in graph[node]:                    
                    if idx != index and max(weight, wei) < dist[nei]:
                        dist[nei] = max(weight, wei)
                        heapq.heappush(minHeap, (max(weight, wei), nei))
            
            return float('inf')

        critical, pseudo = [], []         
        
        for idx, (u,v,w) in enumerate(edges):   
            if w < mst(u,v,idx):
                critical.append(idx)
            elif w == mst(u,v,-1):
                pseudo.append(idx)        
        
        return [critical, pseudo]
            
