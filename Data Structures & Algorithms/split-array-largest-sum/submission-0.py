class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def check(target: int)-> bool:
            count = 1
            curr = 0

            for num in nums:
                if num > target:
                    return False
                if curr + num > target:
                    curr = num
                    count += 1
                else:
                    curr += num

            return count <= k

        
        l = 0
        r = sum(nums)

        while l <= r:
            m = l + (r - l) // 2
            if check(m):
                r = m - 1
            else:
                l = m + 1
        
        return l
