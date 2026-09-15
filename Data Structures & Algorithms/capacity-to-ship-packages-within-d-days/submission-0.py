class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def check(max_weight):
            day = 1
            curr = 0
            
            for weight in weights:                
                if weight > max_weight:
                    return False
                if weight + curr <= max_weight:
                    curr += weight
                else:
                    curr = weight
                    day += 1            
            return day <= days
        
        left = 1
        right = sum(weights)

        while left <= right:
            mid = left + (right-left) // 2
            if check(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left