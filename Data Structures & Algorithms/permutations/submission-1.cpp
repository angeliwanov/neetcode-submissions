class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::unordered_set<int> bag(nums.begin(), nums.end());
        backtrack(result, bag, {}, nums);
        return result;
    }

    static void backtrack(std::vector<std::vector<int>> &result, std::unordered_set<int> &bag,
                          std::vector<int> permutation, std::vector<int> &nums) {
        if (bag.empty()) {
            result.push_back(permutation);
            return;
        }

        for (int num : nums) {
            if (bag.contains(num)) {
                bag.erase(num);
                permutation.push_back(num);
                backtrack(result, bag, permutation, nums);
                permutation.pop_back();
                bag.insert(num);
            }
        }
    }
};
