class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        size_t n = nums.size();
        vector<unordered_map<int, int>> dp (n+1);

        dp[0][0] = 1;

        for (size_t i = 0; i < n; ++i) {
            for (auto& [total, count] : dp[i]) {
                dp[i+1][total+nums[i]] += count;
                dp[i+1][total-nums[i]] += count;
            }
        }

        return dp[n][target];
    }
};
