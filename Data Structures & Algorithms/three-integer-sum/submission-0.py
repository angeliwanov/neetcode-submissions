class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for i, num in enumerate(nums):
            #skip duplicates
            if i > 0 and nums[i] == nums[i-1]:
                continue

            left = i+1
            right = len(nums)-1

            while left < right:
                if num + nums[left] + nums[right] > 0:
                    right -= 1
                elif num + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    res.append([num, nums[left], nums[right]])
                    left += 1
                    #skip duplicates            
                    while left < len(nums) and nums[left] == nums[left-1]:
                        left += 1

        return res