class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes{0};
        int curr{0};

        for (const auto num: nums) {
            curr = num ? curr + 1 : 0;
            maxOnes = max(maxOnes, curr);
        }

        return maxOnes;
    }
};