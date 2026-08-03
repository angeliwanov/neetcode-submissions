class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(set)
        for course, prereq in prerequisites:            
            graph[course].add(prereq)
        courses = [i for i in range(numCourses) if i not in graph]
        
        order = []
        
        while courses:            
            taken = heapq.heappop(courses)
            order.append(taken)

            delete = []
            for course, prereqs in graph.items():
                if taken in prereqs:
                    prereqs.remove(taken)                
                    if not prereqs:
                        heapq.heappush(courses, course)
                        delete.append(course)                
            for d in delete:
                del graph[d]

        return order if len(order) == numCourses else []


        