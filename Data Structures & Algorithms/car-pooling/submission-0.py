class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips = sorted(trips, key=lambda x: x[1])
        car = []
        cap = 0

        for passengers, fro, to in trips:                        
            while car and car[0][0] <= fro:
                _, p = heapq.heappop(car)
                cap -= p            
            if cap + passengers > capacity:                
                return False
            cap += passengers
            heapq.heappush(car, (to, passengers))
        
        return True