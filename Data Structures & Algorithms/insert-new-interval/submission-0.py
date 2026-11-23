class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:          
        res = []
        for i in intervals:
            if newInterval and newInterval[1] < i[0]:
                res.append(newInterval)
                res.append(i)
                newInterval = []
            elif newInterval and i[1] >= newInterval[0]:
                newInterval[0] = min(i[0], newInterval[0])
                newInterval[1] = max(i[1], newInterval[1])
            else:
                res.append(i)
        if newInterval:
            res.append(newInterval)
        return res
             
