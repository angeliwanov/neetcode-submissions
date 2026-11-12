class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)
        for i in range(len(equations)):
            x,y = equations[i]
            value = values[i]
            graph[x].append((y,value))
            graph[y].append((x,1/value))
        
        res = []
        for x,y in queries:
            stack = []
            visited = set()
            if x in graph:
                visited.add(x)
                stack.append((x,1))
            found = False
            while stack:              
                v1, curr1 = stack.pop()
                if v1 == y:
                    res.append(curr1)
                    found = True
                    break
                for v2, curr2 in graph[v1]:
                    if v2 not in visited:
                        visited.add(v2)
                        stack.append((v2, curr1*curr2))
            if not found:
                res.append(-1)
        
        return res