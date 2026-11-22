class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:        
        visited = dict()  

        for num in nums:            
            if num not in visited:
                visited[num] = 1            
            for k,v in visited.items():
                if k >= num:
                    continue
                visited[num] = max(visited[num], v + 1)            
            
        return max(visited.values())