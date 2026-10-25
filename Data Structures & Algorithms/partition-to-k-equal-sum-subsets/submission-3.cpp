class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return false;
        }
        int total {accumulate(nums.begin(), nums.end(), 0)};
        if (total % k != 0) {
            return false;
        }
        int target {total / k};
        if (*max_element(nums.begin(), nums.end()) > target) {
            return false;
        }
        sort(nums.begin(), nums.end(), std::greater<int>());
        vector<int> subsets (k, 0);
        return backtrack(nums, k, subsets, 0, total, target);
    }

    bool backtrack(vector<int>& nums, int& k, vector<int>& subsets,  size_t index, int& total, int& target) {
        if (index == nums.size()) {
            return accumulate(subsets.begin(), subsets.end(), 0) == total;
        }

        for (size_t i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            for (size_t j = 0; j < k; ++j) {
                if (j > 1 && subsets[j] == subsets[j-1]) {
                    continue;
                }
                if (subsets[j] + nums[i] <= target) {
                    subsets[j] += nums[i];
                    if (backtrack(nums, k, subsets, i + 1, total, target)) {
                        return true;
                    }
                    subsets[j] -= nums[i];
                }
            }
        }

        return false;
    }
};