class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        seen = defaultdict(int)
        seen[0] = 1
        curr = result = 0

        for num in nums:
            curr += num
            diff = curr - k
            result += seen[diff]
            seen[curr] += 1
        
        return result