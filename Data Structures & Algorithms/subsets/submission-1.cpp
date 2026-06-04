class Solution {
   private:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, size_t index, vector<int>& subset) {
        result.push_back(subset);

        for (size_t i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(nums, 0, subset);
        return result;
    }
};
