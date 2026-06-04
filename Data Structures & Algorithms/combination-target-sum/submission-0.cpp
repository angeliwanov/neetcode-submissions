class Solution {
    private:
    void backtrack(const vector<int>&nums, int target, size_t index, vector<int>& subset, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }

        for (size_t i = index; i < nums.size(); ++i) {
            if (nums[i] <= target) {
                subset.push_back(nums[i]);
                backtrack(nums, target - nums[i], i, subset, result);
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;        
        vector<vector<int>> result;
        backtrack(nums, target, 0, subset, result);
        return result;
    }
};
