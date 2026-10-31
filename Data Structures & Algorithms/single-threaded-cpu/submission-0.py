class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = [(e,p,i) for i, (e,p) in enumerate(tasks)]        
        heapq.heapify(tasks)
        ready = []
        res = []
        cycle = 1

        while tasks or ready:                  
            while tasks and tasks[0][0] <= cycle:
                task = heapq.heappop(tasks)
                heapq.heappush(ready, (task[1], task[0], task[2]))            
            if ready:
                task = heapq.heappop(ready)
                res.append(task[2])
                cycle += task[0]
            else:
                cycle += 1
        
        return res

        
         