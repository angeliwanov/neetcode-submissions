class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t left{0};

        for (size_t right = 1; right < nums.size(); ++right) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
        }

        return left+1;
    }
};