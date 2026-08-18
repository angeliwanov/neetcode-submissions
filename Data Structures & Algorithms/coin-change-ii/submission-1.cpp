class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> dp (amount+1);
        dp[0] = 1;

        for (auto coin : coins) {
            for (int i = coin; i < amount+1; ++i) {
                dp[i] += dp[i-coin];
            }
        }

        return dp[amount];
    }
};
