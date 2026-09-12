class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea {0};
        stack<pair<int, int>> stk;

        for (int i = 0; i <heights.size(); ++i) {
            int start {i};
            while (!stk.empty() && stk.top().second > heights[i]) {
                auto &[idx, height] = stk.top();
                stk.pop();
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
            }
            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            auto& [idx, height] = stk.top();
            stk.pop();
            maxArea = max(maxArea, height * ((int)heights.size() - idx));
        }
        return maxArea;
    }
};
