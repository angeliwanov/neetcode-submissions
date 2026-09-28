class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left = 0
        count = Counter(t)
        res = ""

        for right in range(len(s)):
            if s[right] in count.keys():
                count[s[right]] -= 1
            while max(count.values()) <= 0:
                if not res or right - left + 1 < len(res):                            
                    res = s[left:right+1]
                if s[left] in count.keys():
                    count[s[left]] += 1                
                left += 1

        return res
