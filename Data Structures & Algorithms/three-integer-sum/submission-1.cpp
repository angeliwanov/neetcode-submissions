class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            size_t left = i + 1;
            size_t right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    --right;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    ++left;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    // skip duplicates
                    while (left < nums.size() && nums[left] == nums[left-1]) {
                        ++left;
                    }
                }
            }
        }
        return res;

    }
};
