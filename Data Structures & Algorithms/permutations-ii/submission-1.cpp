class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        std::vector<std::vector<int>> result;
        backtrack(nums.size(), result, counts, {});
        return result;
    }

    static void backtrack(size_t n, std::vector<std::vector<int>>& result,
                          std::unordered_map<int, int>& counts, std::vector<int> permutation) {
        if (permutation.size() == n) {
            result.push_back(permutation);
            return;
        }

        for (auto [num, count] : counts) {
            if (count > 0) {
                --counts[num];
                permutation.push_back(num);
                backtrack(n, result, counts, permutation);
                permutation.pop_back();
                ++counts[num];
            }
        }
    }
};
