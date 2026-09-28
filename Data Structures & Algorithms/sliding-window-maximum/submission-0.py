class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        left = 0
        heap = []
        res = []        

        for right in range(k-1):            
            heapq.heappush(heap, (-nums[right], right))

        for right in range(k-1, len(nums)):
            heapq.heappush(heap, (-nums[right], right))
            while heap and heap[0][1] < left:
                heapq.heappop(heap)
            res.append(-heap[0][0])                                                                      
            left += 1

        return res