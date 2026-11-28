/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto cmp = [](Interval& a, Interval& b) { return a.start < b.start;};
        std::sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, std::greater<int>> rooms;
        int res{0};

        for (const auto& interval: intervals) {
            if (!rooms.empty() && interval.start >= rooms.top()) {
                rooms.pop();
            }
            rooms.push(interval.end);
            res = max(res, static_cast<int>(rooms.size()));
        }

        return res;
    }
};
