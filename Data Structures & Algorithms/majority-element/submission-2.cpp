class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int res {nums[0]};

        for (const auto& num : nums) {
            ++count[num];
            if (count[num] > count[res]) {
                res = num;
            }
        }

        return res;

    }
};