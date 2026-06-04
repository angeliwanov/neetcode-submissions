class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k{0};

        for (auto const num: nums) {
            if (num != val) {
                nums[k++] = num;
            }
        }

        return k;
    }
};