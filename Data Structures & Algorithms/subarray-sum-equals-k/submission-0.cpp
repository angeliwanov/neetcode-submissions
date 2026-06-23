class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> seen;
        seen.emplace(0,1);
        int curr{0};
        int result{0};
        for (auto num: nums) {
            curr += num;
            int diff = curr - k;
            result += seen[diff];
            seen[curr] += 1;
        }
        return result;
    }   
};