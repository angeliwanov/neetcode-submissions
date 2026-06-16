class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        duplicate = 0
        left = 1

        for right in range(1, len(nums)):
            if nums[right] == nums[right-1]:
                if duplicate == 0:
                    nums[left] = nums[right]
                    left += 1
                duplicate += 1
            else:
                nums[left] = nums[right]
                left += 1
                duplicate = 0
        
        return left