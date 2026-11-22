class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int, int> visited;
        int res {1};

        for (const auto& num: nums) {
            if (visited.find(num) == visited.end()) {
                visited[num] = 1;
            }
            for (const auto& p : visited) {
                if (p.first >= num) {
                    continue;
                }
                visited[num] = max(visited[num], p.second+1);
            }
            res = max(visited[num], res);
        }

        return res;
    }
};
