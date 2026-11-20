class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * (n+1)        
        max_prod = -10        
        neg = None
        for i in range(1, n+1):
            dp[i] = dp[i-1] * nums[i-1]            
            max_prod = max(max_prod, dp[i])                                               
            if dp[i] == 0:
                dp[i] = 1
                neg = deque()
            if dp[i] < 0:
                if neg:
                    max_prod = max(max_prod, dp[i]//neg)                         
                else:
                    neg = dp[i]  
        return max_prod
