class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def bs(l, r):
            while l <= r:
                m = l + (r - l) // 2
                if nums[m] == target:
                    return m
                elif nums[m] > target:
                    r = m - 1
                else:
                    l = m + 1
            return -1

        def pivot(l, r):                    
            while l < r:
                mid = l + (r - l) // 2
                if nums[mid] > nums[r]:
                    l = mid + 1
                else:
                    r = mid
            return l

        p = pivot(0, len(nums) - 1)
        left = bs(0, p-1)
        right = bs(p, len(nums) - 1) 

        return left if left != -1 else right