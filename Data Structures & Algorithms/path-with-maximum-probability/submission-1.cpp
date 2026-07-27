class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node) {
        std::pmr::unordered_map<int, std::vector<std::pair<double, int>>> graph;
        for (size_t i = 0; i < edges.size(); ++i) {
            auto a = edges[i][0];
            auto b = edges[i][1];
            auto prob = succProb[i];
            graph[a].emplace_back(prob, b);
            graph[b].emplace_back(prob, a);
        }

        auto cmp = [](auto& a, auto& b) { return a.first < b.first; };
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>,
                            decltype(cmp)>
            maxHeap;
        double maxProb{0.0};
        std::unordered_set<int> visited;
        for (auto [prob, neigh] : graph[start_node]) {
            maxHeap.emplace(prob, neigh);
        }
        visited.insert(start_node);

        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            visited.insert(node);
            if (node == end_node) {
                maxProb = std::max(maxProb, prob);
            }

            for (auto [deltaProb, neigh] : graph[node]) {
                if (!visited.contains(neigh)) {
                    maxHeap.emplace(deltaProb * prob, neigh);
                }
            }
        }

        return maxProb;
    }
};