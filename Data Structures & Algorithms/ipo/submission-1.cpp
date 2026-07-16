class Solution {
public:
    int findMaximizedCapital(int maxProjects, int startCapital, vector<int>& profits, vector<int>& capital) {
        using Project = std::pair<int, int>;
        auto cmp = [](Project &p1, Project &p2) { return p1.first > p2.first; };
        std::priority_queue<Project, std::vector<Project>, decltype(cmp)> minCapital;
        std::priority_queue<int, std::vector<int>, std::less<>> maxProfit;

        for (size_t i = 0; i < profits.size(); ++i) {
            minCapital.emplace(capital[i], profits[i]);
        }

        while (maxProjects > 0) {
            while (!minCapital.empty() && startCapital >= minCapital.top().first) {
                auto [_, profit] = minCapital.top();
                minCapital.pop();
                maxProfit.emplace(profit);
            }

            if (maxProfit.empty()) {
                break;
            }

            startCapital += maxProfit.top();
            maxProfit.pop();
            --maxProjects;
        }

        return startCapital;
 
    }
};