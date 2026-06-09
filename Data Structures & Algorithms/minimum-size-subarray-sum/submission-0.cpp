class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t left{0};
        int sum {0};
        int minLen {1000000};
        for (size_t right = 0; right < nums.size(); ++right) {
            sum += nums[right];            
            while (sum >= target) {
                minLen = std::min(minLen, static_cast<int>(right - left + 1));
                sum -= nums[left++];
            }
        }   
        return minLen == 1000000 ? 0 : minLen;
    }
};