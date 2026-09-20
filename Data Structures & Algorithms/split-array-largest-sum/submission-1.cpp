class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l {0};
        int r {accumulate(nums.begin(), nums.end(), 0)};

        while (l <= r) {
            int m {l + (r-l) / 2};
            if (check(m, k, nums)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    bool check(int& target, int& k, vector<int>& nums) {
        int count{1};
        int curr{0};

        for (const auto& num: nums) {
            if (num > target) {
                return false;
            } else if (num + curr > target) {
                ++count;
                curr = num;
            } else {
                curr += num;
            }
        }

        return count <= k;
    }
};