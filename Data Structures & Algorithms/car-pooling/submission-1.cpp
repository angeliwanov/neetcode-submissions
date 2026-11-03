class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {return v1[1] < v2[1];};
        sort(trips.begin(), trips.end(), cmp);
        auto cmpq = [](const vector<int>& v1, const vector<int>& v2) {return v1[0] > v2[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmpq)> pq;
        int cap {0};

        for (const auto& trip: trips) {
            while (!pq.empty() && pq.top()[0] <= trip[1]) {
                auto v = pq.top();
                pq.pop();
                cap -= v[1];
            }
            if (cap + trip[0] > capacity) {
                return false;
            }
            cap += trip[0];
            pq.push({trip[2], trip[0]});
        }

        return true;
    }
};