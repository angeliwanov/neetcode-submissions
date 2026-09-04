class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(0, nums.size()-1, nums);
        reverse(0, k % nums.size() - 1, nums);
        reverse(k % nums.size(), nums.size()-1, nums);
    }

    void reverse(int left, int right, vector<int>& nums) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }

};