class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> prereqs;
        for (auto& p : prerequisites) {
            prereqs[p[0]].insert(p[1]);
        }
        stack<int> no_prereqs {};
        for (int i = 0; i < numCourses; i++) {
            if (!prereqs.contains(i)) {
                no_prereqs.push(i);
            }
        }

        int taken {0};
        while (!no_prereqs.empty() && taken < numCourses) {            
            int c = no_prereqs.top();
            no_prereqs.pop();
            ++taken;

            vector<int> toDelete {};
            for (auto& [course, prereq]: prereqs) {
                prereq.erase(c);
                if (prereq.empty()) {
                    no_prereqs.push(course);
                    toDelete.push_back(course);                    
                }
            }

            for (auto c : toDelete) {
                prereqs.erase(c);
            }

            
        }

        return taken == numCourses;
    }
};
