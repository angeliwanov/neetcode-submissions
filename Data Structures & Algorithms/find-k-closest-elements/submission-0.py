class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        cur = deque()
        cur_dif = 0
        for i in range(k):
            cur.append(arr[i])
            cur_dif += abs(x - arr[i])
        
        res = list(cur)
        min_dif = cur_dif

        for i in range(k, len(arr)):
            popped = cur.popleft()
            cur.append(arr[i])
            cur_dif -= abs(x - popped)
            cur_dif += abs(x - arr[i])            
            if cur_dif < min_dif:
                min_dif = cur_dif
                res = list(cur)

        return res