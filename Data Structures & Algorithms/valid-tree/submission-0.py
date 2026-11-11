class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for x,y in edges:
            graph[x].append(y)            
            graph[y].append(x)            
        
        edges = set()
        nodes = {0}       
        stack = [0]
        
        while stack:
            node = stack.pop()
            for nei in graph[node]:
                if nei not in nodes:
                    nodes.add(nei)
                    edges.add((node,nei))                    
                    stack.append(nei)
                elif (nei,node) not in edges:
                        return False                
        
        return len(nodes) == n