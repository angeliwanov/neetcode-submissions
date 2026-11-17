class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }

        //take first house
        vector<int> dp (nums.size()+1, 0);
        dp[1] = nums[0];
        for (size_t i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        //skip first house
        vector<int> dp2 (nums.size()+1, 0);
        for (size_t i = 2; i < nums.size()+1; ++i) {
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i-1]);
        }

        return max(dp[nums.size()-1], dp2[nums.size()]);
    }
};
