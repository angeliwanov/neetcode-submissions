class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(perm, bag):
            if not bag:
                res.append(perm[:])
                return

            for num in nums:
                if num  in bag:                    
                    bag.remove(num)
                    perm.append(num)
                    backtrack(perm, bag)
                    perm.pop()
                    bag.add(num)

        backtrack([], set(nums))
        return res
