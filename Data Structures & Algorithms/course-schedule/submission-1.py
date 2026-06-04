class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        prereqs = defaultdict(set)
        for c, p in prerequisites:
            prereqs[c].add(p)
        no_prereqs = []
        for i in range(numCourses):
            if i not in prereqs:
                no_prereqs.append(i)

        taken = 0
        while no_prereqs:
            c = no_prereqs.pop()
            taken += 1

            to_remove = []
            for course, prereq in prereqs.items():
                prereq.discard(c)
                if not prereq:
                    no_prereqs.append(course)
                    to_remove.append(course)
            
            for rem in to_remove:
                del prereqs[rem]
        
        return taken == numCourses

        