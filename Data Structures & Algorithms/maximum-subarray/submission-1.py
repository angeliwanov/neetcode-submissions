class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        curSum = nums[0]

        for i in range(1,len(nums)):
            curSum = max(0, curSum)
            curSum += nums[i]
            maxSum = max(curSum, maxSum)

        return maxSum