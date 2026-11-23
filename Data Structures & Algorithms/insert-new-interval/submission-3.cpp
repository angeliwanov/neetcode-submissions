class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (const auto& i: intervals) {
            if (!newInterval.empty() && newInterval[1] < i[0]) {
                res.push_back(newInterval);
                res.push_back(i);
                newInterval.clear();
            } else if (!newInterval.empty() && i[1] >= newInterval[0]) {
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            } else {
                res.push_back(i);
            }
        }

        if (!newInterval.empty()) {
            res.push_back(newInterval);
        }

        return res;
    }

};
