class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        return backtrack(subset, 0, nums);
    }

    int backtrack(vector<int>& subset, size_t index, vector<int>& nums) {
        if (index == nums.size()) {
            return 0;
        }

        int total {0};

        for (size_t i = index; i < nums.size(); ++i) {
            subset.emplace_back(nums[i]);
            int subsetXor {subset[0]};
            for (size_t j = 1; j < subset.size(); ++j) {
                subsetXor ^= subset[j];
            }
            total += subsetXor + backtrack(subset, i + 1, nums);            
            subset.pop_back();
        }

        return total;
    }
};