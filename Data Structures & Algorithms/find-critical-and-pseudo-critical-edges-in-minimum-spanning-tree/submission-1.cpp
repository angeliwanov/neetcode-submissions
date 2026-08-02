class Solution {
   public:
    static int mst(int numNodes, std::unordered_map<int, std::vector<std::vector<int>>> graph,
                   int include, int exclude, const std::vector<std::vector<int>>& edges) {
        auto cmp = [](const std::pair<int, int>& e1, const std::pair<int, int>& e2) {
            return e1.second > e2.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>
            minHeap;
        int cost{0};
        std::unordered_set<int> visited;

        // if include, add its cost and append neighbors
        if (include != -1) {
            auto u = edges[static_cast<size_t>(include)][0];
            auto v = edges[static_cast<size_t>(include)][1];
            cost += edges[static_cast<size_t>(include)][2];
            visited.insert(u);
            visited.insert(v);
            for (auto node : graph[u]) {
                auto nei = node[0];
                auto wei = node[1];
                minHeap.emplace(nei, wei);
            }
            for (auto node : graph[v]) {
                auto nei = node[0];
                auto wei = node[1];
                minHeap.emplace(nei, wei);
            }
        } else {
            // if exclude start from 0
            minHeap.emplace(0, 0);
        }

        while (!minHeap.empty() && static_cast<int>(visited.size()) < numNodes) {
            auto [node, weight] = minHeap.top();
            minHeap.pop();

            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);
            cost += weight;

            for (auto vertex : graph[node]) {
                auto nei = vertex[0];
                auto wei = vertex[1];
                auto idx = vertex[2];
                // if exclude build normal mst skipping the index
                if (idx != exclude && !visited.contains(nei)) {
                    minHeap.emplace(nei, wei);
                }
            }
        }

        return static_cast<int>(visited.size()) == numNodes ? cost : 1000000;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int numNodes,
                                                           vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<std::vector<int>>> graph;
        for (size_t i = 0; i < edges.size(); ++i) {
            const auto& edge = edges[i];
            auto u = edge[0];
            auto v = edge[1];
            auto w = edge[2];
            graph[u].push_back({v, w, static_cast<int>(i)});
            graph[v].push_back({u, w, static_cast<int>(i)});
        }

        // the output
        std::vector<std::vector<int>> output(2);

        // iterate over all edges
        for (size_t i = 0; i < edges.size(); ++i) {
            // calcualte mst by taking the index
            auto mst_with = mst(numNodes, graph, static_cast<int>(i), -1, edges);
            // mst by excluding the index
            auto mst_without = mst(numNodes, graph, -1, static_cast<int>(i), edges);
            if (mst_with < mst_without) {
                // mst_with < mst_without - critical
                output[0].push_back(static_cast<int>(i));
            } else if (mst_with == mst_without) {
                // mst_with == mst_without - pseudo
                output[1].push_back(static_cast<int>(i));
            } else {
                // mst_with > mst_without - not considered
                continue;
            }
        }

        return output;
    }
};