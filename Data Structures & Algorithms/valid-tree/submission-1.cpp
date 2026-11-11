class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited_nodes;
        unordered_set<int> visited_edges;
        stack<int> stk;

        stk.push(0);
        visited_nodes.insert(0);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            cout << node << endl;
            for (const auto& nei: graph[node]) {               
                if (visited_nodes.find(nei) == visited_nodes.end()) {
                    visited_nodes.insert(nei);
                    stk.push(nei);
                    visited_edges.insert(node*2000 + nei);                    
                } else if (visited_edges.find(nei*2000 + node) == visited_edges.end()) {
                    return false;
                }
            }
        }

        return visited_nodes.size() == n;
    }
};
