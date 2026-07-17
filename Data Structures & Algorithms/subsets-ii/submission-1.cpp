class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        std::ranges::sort(nums);
        backtrack(result, subset, 0, nums);
        return result;
    }

    static void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& subset,
                          size_t index, std::vector<int>& nums) {
        result.push_back(subset);

        for (size_t i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            backtrack(result, subset, i + 1, nums);
            subset.pop_back();
        }
    }
};
