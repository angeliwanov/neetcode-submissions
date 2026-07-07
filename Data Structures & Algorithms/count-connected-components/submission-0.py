class Solution:    
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        def find(n):
            p = parent[n]
            while p != parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]
            return p
        
        def union(n1,n2):
            p1 = find(n1)
            p2 = find(n2)

            if p1 == p2:
                return False
            
            if rank[p1] > rank[p2]:
                rank[p1] += rank[p2]
                parent[p2] = p1
            else:
                rank[p2] += rank[p1]
                parent[p1] = p2
            return True

        parent = [i for i in range(n)]
        rank = [1] * n

        components = n
        for edge in edges:
            if union(edge[0], edge[1]):
                components -=1
            
        
        return components

     