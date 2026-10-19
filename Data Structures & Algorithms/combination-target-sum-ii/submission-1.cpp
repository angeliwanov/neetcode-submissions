class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> res;
        dp(subset, res, 0, target, candidates);
        return res;
    }

    void dp(vector<int>& subset, vector<vector<int>>& res, size_t index, int currSum,
            vector<int>& candidates) {
        if (currSum == 0) {
            res.push_back(subset);
            return;
        }

        for (size_t i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= currSum) {
                subset.push_back(candidates[i]);
                dp(subset, res, i + 1, currSum - candidates[i], candidates);
                subset.pop_back();
            }
        }
    }
};
