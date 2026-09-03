class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (size_t i = 0; i < nums.size(); ++i) {
            //skip duplicates
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }

            for (size_t j = i+1; j < nums.size(); ++j) {
                //skip duplicates
                if (j > i+1 and nums[j] == nums[j-1]) {
                    continue;
                }

                size_t left = j+1;
                size_t right = nums.size() - 1;

                while (left < right) {

                    if ((long long) nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        --right;
                    } else if ((long long) nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        ++left;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        //skip duplicates
                        while (left < nums.size() and nums[left] == nums[left-1]) {
                            ++left;
                        }
                        
                    }
                }
            }
        }

        return res;

    }
};