class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()        
        seen = [intervals[0]]
        count = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < seen[-1][1]:
                count += 1
                if intervals[i][1] < seen[-1][1]:
                    seen[-1] = intervals[i]
            else:
                seen.append(intervals[i])
        return count
