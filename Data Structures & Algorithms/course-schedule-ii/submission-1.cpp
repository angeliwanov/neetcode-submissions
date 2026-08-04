class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build a graph with all courses and their respective prerequisites
        std::unordered_map<int, std::unordered_set<int>> graph;
        for (const auto& prereq : prerequisites) {
            graph[prereq[0]].insert(prereq[1]);
        }
        // build a minHeap with all courses without prerequisites
        std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
        for (int i = 0; i < numCourses; ++i) {
            if (!graph.contains(i)) {
                minHeap.push(i);
            }
        }
        // build the output
        std::vector<int> output;

        // exhaust the minHeap by taking the smallest numCourse that is available
        while (!minHeap.empty()) {
            // append the coure taken to the output to produce an ordered result
            auto course = minHeap.top();
            minHeap.pop();
            output.push_back(course);

            std::vector<int> toBeDeleted;
            for (auto& [c, p] : graph) {
                auto it = p.find(course);
                if (it != p.end()) {
                    p.erase(it);
                    // after taking that course, check if it free another course and add it to the
                    // minHeap
                    if (p.empty()) {
                        toBeDeleted.push_back(c);
                        minHeap.push(c);
                    }
                }
            }

            for (int i : toBeDeleted) {
                graph.erase(graph.find(i));
            }
        }

        // return output if graph is empty
        return graph.empty() ? output : std::vector<int>{};
    }
};
