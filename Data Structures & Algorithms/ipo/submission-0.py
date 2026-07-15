class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        min_capital = list(zip(capital, profits))
        heapq.heapify(min_capital)
        max_profit = []        

        while k:
            while min_capital and w >= min_capital[0][0]:
                _, profit = heapq.heappop(min_capital)
                heapq.heappush(max_profit, -profit)
            if not max_profit:
                break
            w += -heapq.heappop(max_profit)
            k -= 1
        
        return w