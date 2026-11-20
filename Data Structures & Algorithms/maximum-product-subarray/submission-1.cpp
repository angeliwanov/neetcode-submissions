class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        vector<int> dp (nums.size()+1, 1);
        int neg {-11};
        int res {nums[0]};

        for (size_t i = 1; i < nums.size()+1; ++i) {
            dp[i] = dp[i-1] * nums[i-1];
            res = max(res, dp[i]);
            if (dp[i] == 0) {
                neg = -11;
                dp[i] = 1;
            } else if (dp[i] < 0) {
                if (neg > -11) {
                    res = max(res, dp[i] / neg);
                } else {
                    neg = dp[i];
                }
            }
        }

        return res;
    }
};
