class Solution {
   private:
    void backtrack(vector<int>& nums, size_t index, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);

        for (size_t i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset, result);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }
};
