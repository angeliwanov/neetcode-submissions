class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxFreq = 0
        maxLen = 0
        left = 0
        chars = defaultdict(int)

        for right in range(len(s)):
            chars[s[right]] += 1
            maxFreq = max(maxFreq, chars[s[right]])
            while right - left + 1 - maxFreq > k:
                chars[s[left]] -= 1
                left += 1
            maxLen = max(maxLen, right - left + 1)
        
        return maxLen
