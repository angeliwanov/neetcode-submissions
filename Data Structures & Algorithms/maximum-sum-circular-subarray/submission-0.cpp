class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int global_max {nums[0]};
        int curr_max {nums[0]};
        int global_min {nums[0]};
        int curr_min {nums[0]};
        int total {nums[0]};
        
        for (size_t i = 1; i < nums.size(); ++i) {
            total += nums[i];

            curr_max = max(curr_max, 0);
            curr_max += nums[i];
            global_max = max(global_max, curr_max);

            curr_min = min(curr_min, 0);
            curr_min += nums[i];
            global_min = min(global_min, curr_min);

        }

        return global_max > 0 ? max(global_max, total - global_min) : global_max;
    }
};