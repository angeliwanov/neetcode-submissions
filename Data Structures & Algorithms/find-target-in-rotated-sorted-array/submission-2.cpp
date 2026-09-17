class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = pivot(nums, 0, nums.size() - 1);
        int left = bs(nums, 0, p-1, target);
        int right = bs(nums, p, nums.size()-1, target);
        return left != -1 ? left : right;
    }

    int pivot(vector<int>& nums, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int bs(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
