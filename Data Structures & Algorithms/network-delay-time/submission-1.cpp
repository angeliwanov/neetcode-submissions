class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<std::vector<int>>> edges;
        for (auto time : times) {
            edges[time[0]].push_back({time[1], time[2]});
        }

        auto cmp = [](const auto& p1, const auto& p2) { return p1.second > p2.second; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>
            minHeap;
        minHeap.emplace(k, 0);

        int time = 0;
        std::unordered_set<int> visited;

        while (!minHeap.empty()) {
            auto [node, weight] = minHeap.top();
            minHeap.pop();

            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);
            time = weight;

            for (auto neighbor : edges[node]) {
                minHeap.emplace(neighbor[0], neighbor[1] + weight);
            }
        }
        return visited.size() == static_cast<size_t>(n) ? time : -1;
    }
};
