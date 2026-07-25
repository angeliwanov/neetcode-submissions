class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto cmp = [](const auto& a, const auto& b) { return a[0] > b[0]; };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> minHeap;

        minHeap.push({grid[0][0], 0, 0});
        std::set<std::pair<int, int>> visited;
        int time{0};
        while (!minHeap.empty()) {
            auto node = minHeap.top();
            minHeap.pop();

            if (visited.contains({node[1], node[2]})) {
                continue;
            }

            visited.insert({node[1], node[2]});
            time = std::max(time, node[0]);

            if (node[1] == n - 1 && node[2] == n - 1) {
                return time;
            }

            for (auto [x, y] : directions) {
                int nx = x + node[1];
                int ny = y + node[2];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited.contains({nx, ny})) {
                    minHeap.push({grid[static_cast<size_t>(nx)][static_cast<size_t>(ny)], nx, ny});
                }
            }
        }

        return -1;
    }
};
