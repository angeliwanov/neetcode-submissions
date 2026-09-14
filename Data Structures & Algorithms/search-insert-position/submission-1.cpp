class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left {0};
        int right {static_cast<int>(nums.size())};

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[static_cast<size_t>(mid)] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};