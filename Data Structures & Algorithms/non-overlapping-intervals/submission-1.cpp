class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> seen;
        seen.emplace_back(intervals[0]);       
        int count {0};

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < seen.back()[1]) {
                ++count;
                if (intervals[i][1] < seen.back()[1]) {
                    seen.back() = intervals[i];
                }
            } else {
                seen.emplace_back(intervals[i]);
            }
        }

        return count;
    }
};
