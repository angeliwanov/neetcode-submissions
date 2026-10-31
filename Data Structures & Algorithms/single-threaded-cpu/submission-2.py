class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        waiting = [(task[0],i) for i, task in enumerate(tasks)]        
        heapq.heapify(waiting)
        ready = []
        res = []
        cycle = 1

        while waiting or ready:                  
            while waiting and waiting[0][0] <= cycle:
                _,idx = heapq.heappop(waiting)
                heapq.heappush(ready, (tasks[idx][1], idx))            
            if ready:
                running = heapq.heappop(ready)
                res.append(running[1])
                cycle += running[0]
            else:
                cycle += 1
        
        return res

        
         