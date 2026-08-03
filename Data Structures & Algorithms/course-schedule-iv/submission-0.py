class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = defaultdict(set)
        for prereq, course in prerequisites:
            graph[course].add(prereq)
        
        def dfs(course, prereq):
            stack = [course]
            visited = set()
            visited.add(course)

            while stack:
                c = stack.pop()                

                if c == prereq:
                    return True

                for p in graph[c]:
                    if p not in visited:
                        visited.add(p)
                        stack.append(p)

            return False

        res = []
        for prereq, course in queries:
            res.append(dfs(course, prereq))
        return res