class Solution:
    def reorganizeString(self, s: str) -> str:        
        heap = [(-v,k) for k,v in Counter(s).items()]
        heapq.heapify(heap)
        res = ""

        while len(heap) > 1:
            count1, ch1 = heapq.heappop(heap)            
            count2, ch2 = heapq.heappop(heap)
            res += ch1            
            res += ch2
            if count1 != -1:
                heapq.heappush(heap, (count1+1,ch1))
            if count2 != -1:
                heapq.heappush(heap, (count2+1,ch2))
        
        if heap:
            if heap[0][0] != -1:
                return ""
            else:
                res += heap[0][1]
                
        return res