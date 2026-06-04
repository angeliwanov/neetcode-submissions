class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_ones = 0
        curr = 0

        for num in nums:
            if num == 1:
                curr += 1
            else:
                curr = 0
            max_ones = max(max_ones, curr)

        return max_ones