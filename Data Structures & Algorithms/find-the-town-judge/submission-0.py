class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        in_order = [0] * n
        out_order = [0] * n        
        
        for x,y in trust:
            out_order[x-1] += 1
            in_order[y-1] += 1
        
        for i in range(n):
            if in_order[i] == n - 1 and out_order[i] == 0:
                return i + 1

        return -1
