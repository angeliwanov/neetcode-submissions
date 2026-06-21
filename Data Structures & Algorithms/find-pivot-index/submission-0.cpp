class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left {0};
        int right {std::accumulate(nums.begin(), nums.end(), 0)};        

        for (size_t i = 0; i < nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }

        return -1;
    }
};