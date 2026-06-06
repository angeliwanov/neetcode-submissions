class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        curr_max = glob_max = curr_min = glob_min = total = nums[0]
        
        for i in range(1, len(nums)):
            curr_max = max(curr_max, 0)
            curr_max += nums[i]
            glob_max = max(glob_max, curr_max)

            curr_min = min(curr_min, 0)
            curr_min += nums[i]
            glob_min = min(glob_min, curr_min)

            total += nums[i]

        return glob_max if glob_max < 0 else max(glob_max, total - glob_min)