class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        max_heap = []
        for key, value in counter.items():
            heapq.heappush(max_heap, (-value, key))
        
        res = []            
        while max_heap and k > 0:                      
            _, num = heapq.heappop(max_heap)
            res.append(num)
            k -= 1

        return res