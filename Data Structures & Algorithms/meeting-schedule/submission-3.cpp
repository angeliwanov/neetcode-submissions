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
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto cmp = [](Interval& a, Interval& b) {return a.start < b.start;};
        std::sort(intervals.begin(), intervals.end(), cmp);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }

        return true;
    }
};
