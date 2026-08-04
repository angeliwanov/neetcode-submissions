class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        static_cast<void>(numCourses);
        // container to hold the output
        std::vector<bool> output;
        output.reserve(queries.size());
        // build a graph - a hash map of courses with all their dependencies as a set
        std::unordered_map<int, std::unordered_set<int>> graph;
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].insert(prereq[0]);
        }
        // for each query run a dfs, searching for the dstCourse
        for (auto query : queries) {
            std::unordered_set<int> visited;
            visited.insert(query[0]);
            visited.insert(query[1]);
            output.push_back(dfs(graph, query[0], query[1], visited));
        }

        // return the output
        return output;
    }

    static bool dfs(std::unordered_map<int, std::unordered_set<int>>& graph, int src, int dst,
                    std::unordered_set<int>& visited) {
        if (!graph.contains(dst)) {
            return false;
        }

        for (auto prereq : graph[dst]) {
            if (prereq == src) {
                return true;
            }
            if (!visited.contains(prereq)) {
                visited.insert(prereq);
                if (dfs(graph, src, prereq, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};