class Solution:
    def validPalindrome(self, s: str) -> bool:
        def palindrome(left, right, mismatch):           
            if left >= right:
                return True
            
            if s[left] == s[right]:
                return palindrome(left+1, right-1, mismatch)
            else:
                if mismatch == 0:
                    return False                                
                return palindrome(left+1, right, mismatch -1) or palindrome(left, right-1, mismatch-1)
        
        return palindrome(0, len(s)-1, 1)