class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum {nums[0]};
        int currSum {nums[0]};

        for (size_t i = 1; i < nums.size(); ++i) {
            currSum = std::max(currSum, 0);
            currSum += nums[i];
            maxSum = std::max(currSum, maxSum);
        }

        return maxSum;
    }
};
