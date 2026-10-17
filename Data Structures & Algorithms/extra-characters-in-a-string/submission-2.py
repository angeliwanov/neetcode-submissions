class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        dic = {s for s in dictionary}
        cache = {}
        
        def dp(i):
            if i == len(s):
                return 0
            if i in cache:
                return cache[i]

            ans = 1 + dp(i+1)            
            for j in range(i, len(s)):
                if s[i:j+1] in dic:
                    ans = min(ans, dp(j+1))
            
            cache[i] = ans
            return ans

        return dp(0)