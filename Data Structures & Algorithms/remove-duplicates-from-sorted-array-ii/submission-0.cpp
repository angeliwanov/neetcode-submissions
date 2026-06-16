class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicate{0};
        size_t left{1};

        for (size_t right = 1; right < nums.size(); ++right) {
            if (nums[right] == nums[right-1]) {
                if (duplicate == 0) {
                    nums[left++] = nums[right];
                } 
                ++duplicate;
            } else {
                nums[left++] = nums[right];
                duplicate = 0;
            }
        }

        return left;
    }
};