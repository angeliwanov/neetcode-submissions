class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int idx = 0;

        while (idx <= right) {
            if (nums[idx] == 0) {
                std::swap(nums[idx++], nums[left++]);
            } else if (nums[idx] == 2) {
                std::swap(nums[idx], nums[right--]);
            } else {
                idx++;
            }
        }        
    }
};