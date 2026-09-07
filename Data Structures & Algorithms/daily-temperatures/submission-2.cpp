class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0); 
        stack<pair<size_t, int>> stk;

        for (size_t i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && stk.top().second < temperatures[i]) {
                auto p = stk.top();
                stk.pop();
                res[p.first] = i - static_cast<int>(p.first);
            }
            stk.push({i, temperatures[i]});
        }

        return res;
    }
};
