class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap = [(-count, char) for count, char in zip([a, b, c], ['a', 'b', 'c']) if count > 0]
        heapq.heapify(heap)        
        
        res = ""
        while heap:
            count, char = heapq.heappop(heap)             
            if len(res) >= 2 and res[-2] == char and res[-1] == char:
                if heap:
                    count2, char2 = heapq.heappop(heap)
                    res += char2                  
                    if count2 != -1:
                        heapq.heappush(heap, (count2+1, char2))
                else:
                    continue        
            res += char 
            if count != -1:           
                heapq.heappush(heap, (count+1, char))
        return res