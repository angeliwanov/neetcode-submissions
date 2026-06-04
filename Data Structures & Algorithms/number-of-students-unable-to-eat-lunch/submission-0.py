class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:        
        students = deque(students)
        sandwiches = sandwiches[::-1]        
        taken = True

        while taken:
            taken = False            
            length = len(students)
            for _ in range(length):
                student = students.popleft()
                if student == sandwiches[-1]:
                    sandwiches.pop()
                    taken = True                    
                else:
                    students.append(student)

        return len(students)
