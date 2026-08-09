class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;

        size_t n = nums.size();
        std::vector<std::vector<bool>> dp (n+1, std::vector<bool> (target+1, false));

        for (size_t i = 0; i < n+1; ++i) {
            dp[i][0] = true;
        }

        for (size_t i = 1; i < n+1; ++i) {
            for (size_t j = 1; j < target+1; ++j) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];

    }
};
