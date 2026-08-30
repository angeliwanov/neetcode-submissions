class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        def dp(i, stock):
            if i == len(prices):
                return 0 

            if (i,stock) in memo:
                return memo[(i,stock)]
            
            buy, sell = 0, 0
            if stock:
                sell = prices[i] + dp(i+1, False)
            else:
                buy = -prices[i] + dp(i+1, True)
            skip = dp(i+1, stock)

            memo[(i,stock)] = max(sell, buy, skip)
            return memo[(i,stock)]
        
        memo = dict()
        return dp(0, False)
            