class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto cmp = [](pair<int,int>p1, pair<int,int>p2) {return p1.first > p2.first;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> waiting;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> ready;
        vector<int> res;
        int cycle{1};

        for (size_t i = 0; i < tasks.size(); ++i) {
            waiting.push({tasks[i][0], i});            
        }

        while (!waiting.empty() || !ready.empty()) {
            while (!waiting.empty() && waiting.top().first <= cycle) {
                auto idx = waiting.top().second;
                waiting.pop();
                ready.push({tasks[idx][1], idx});
            }
            if (!ready.empty()) {
                auto running = ready.top();
                ready.pop();
                res.emplace_back(running.second);
                cycle += running.first;
            } else {
                cycle += 1;
            }
        }

        return res;
    }
};