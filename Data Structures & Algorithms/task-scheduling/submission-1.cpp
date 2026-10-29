class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> order;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& task : tasks) {
            if (order.find(task) == order.end()) {
                order[task] = 0;
            } else {
                order[task] += n + 1;
            }
            q.push(order[task]);
        }

        int i {0};
        while (!q.empty()) {
            if (i >= q.top()) {
                q.pop();
            }
            ++i;
        }

        return i;
    }
};
