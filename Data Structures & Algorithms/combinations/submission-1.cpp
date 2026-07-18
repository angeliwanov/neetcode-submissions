class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> comb;
        backtrack(result, comb, 1, n, k);
        return result;
    }

    static void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& comb, int index,
                          int maxNumber, int pickCount) {
        if (comb.size() == static_cast<size_t>(pickCount)) {
            result.push_back(comb);
            return;
        }

        for (int i = index; i <= maxNumber; ++i) {
            comb.push_back(i);
            backtrack(result, comb, i + 1, maxNumber, pickCount);
            comb.pop_back();
        }
    }
};