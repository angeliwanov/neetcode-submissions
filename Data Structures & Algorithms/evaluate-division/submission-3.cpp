class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> graph;
        for (size_t i = 0; i < values.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> res;
        for (const auto& q: queries) {
            stack<pair<string,double>> stk;
            unordered_set<string> visited;
            if (graph.find(q[0]) != graph.end()) {
                stk.push({q[0],1});
                visited.insert(q[0]);
            }

            bool found {false};
            while (!stk.empty()) {
                auto [x, curr] = stk.top();
                stk.pop();
                if (x == q[1]) {
                    res.push_back(curr);
                    found = true;
                    break;
                }
                for (const auto& [y, val]: graph[x]) {
                    if (visited.find(y) == visited.end()) {
                        visited.insert(y);
                        stk.push({y, curr*val});
                    }
                }

            }

            if (!found) {
                res.push_back(-1);
            }
        }

        return res;

    }
};