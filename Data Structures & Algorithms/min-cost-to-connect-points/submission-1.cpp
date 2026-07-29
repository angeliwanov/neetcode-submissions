class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using Point = std::pair<int, int>;
        std::unordered_map<int, std::vector<Point>> graph;
        std::unordered_set<int> visited;
        for (size_t i = 0; i < points.size() - 1; ++i) {
            auto x1 = points[i][0];
            auto y1 = points[i][1];
            for (size_t j = i + 1; j < points.size(); ++j) {
                auto x2 = points[j][0];
                auto y2 = points[j][1];
                auto dist = std::abs(x1 - x2) + std::abs(y1 - y2);
                graph[static_cast<int>(i)].emplace_back(j, dist);
                graph[static_cast<int>(j)].emplace_back(i, dist);
            }
        }

        auto cmp = [](const auto& p1, const auto& p2) { return p1.second > p2.second; };
        std::priority_queue<Point, std::vector<Point>, decltype(cmp)> minHeap;
        minHeap.emplace(0, 0);
        int cost{0};

        while (visited.size() < points.size()) {
            auto [node, dist] = minHeap.top();
            minHeap.pop();
            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);
            cost += dist;

            for (auto& [nei, wei] : graph[node]) {
                if (!visited.contains(nei)) {
                    minHeap.emplace(nei, wei);
                }
            }
        }
        return cost;
    }
};
