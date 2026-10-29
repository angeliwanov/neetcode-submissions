class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dic = dict()
        heap = []
        for task in tasks:
            if task not in dic:
                dic[task] = 0
            else:
                dic[task] += n + 1
            heapq.heappush(heap, dic[task])
        
        i = 0        
        while heap:        
            if i >= heap[0]:
                heapq.heappop(heap)
            i += 1
        
        return i
       