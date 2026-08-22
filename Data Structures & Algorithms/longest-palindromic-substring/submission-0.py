class Solution:
    def longestPalindrome(self, s: str) -> str:        
        result = ""
        res_len = 0

        for i in range(len(s)):
            # odd length
            left = right = i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if right - left + 1 > res_len:
                    result = s[left:right+1]
                    res_len = right - left + 1
                left -= 1
                right += 1
            
            # event length 
            left = i
            right = i + 1
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if right - left + 1 > res_len:
                    res_len = right - left + 1
                    result = s[left:right+1]
                left -= 1
                right += 1
        
        return result