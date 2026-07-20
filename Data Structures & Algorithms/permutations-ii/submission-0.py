class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        bag = Counter(nums)        

        def backtrack(perm):
            if len(perm) == len(nums):
                res.append(perm[:])
                return

            for num in bag:
                if bag[num] > 0:
                    bag[num] -= 1
                    perm.append(num)
                    backtrack(perm)
                    perm.pop()
                    bag[num] += 1
        
        backtrack([])
        return res