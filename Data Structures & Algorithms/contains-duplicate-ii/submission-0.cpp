class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> visited;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (visited.find(nums[i]) != visited.end()) {
                if (i - visited[nums[i]] <= k) {
                    return true;
                }
            }
            visited[nums[i]] =  static_cast<int>(i);
        }

        return false;
    }
};