class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        visited = {}

        for i in range(len(nums)):
            if nums[i] in visited and i - visited[nums[i]] <= k:
                return True
            visited[nums[i]] = i
        
        return False
                