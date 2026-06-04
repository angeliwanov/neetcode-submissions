class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(speed):
            time = 0
            for pile in piles:
                time += math.ceil(pile / speed)
            return time <= h
        
        low = 1
        high = max(piles)

        while low <= high:
            mid = low + (high - low) // 2
            if check(mid):
                high = mid - 1
            else:
                low = mid + 1
        
        return low