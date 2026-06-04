class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using Point = tuple<int, int, int>;
        priority_queue<Point, vector<Point>, std::less<Point>> maxHeap;
        for (auto& point: points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, point[0], point[1]});
            if (maxHeap.size() > static_cast<size_t>(k)) {
                maxHeap.pop();
            }
        }

        std::vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto [dist, x, y] = maxHeap.top();
            ans.push_back({x, y});
            maxHeap.pop();
        }

        return ans;
    }
};
