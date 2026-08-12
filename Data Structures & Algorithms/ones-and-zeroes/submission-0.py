class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = defaultdict(int)

        for s in strs:
            zeros = s.count("0")
            ones = s.count("1")
            for zero in range(m, zeros-1, -1):
                for one in range(n, ones-1, -1):
                    dp[(zero,one)] = max(dp[(zero,one)], 1+dp[(zero-zeros,one-ones)])
        
        return dp[(m,n)]
