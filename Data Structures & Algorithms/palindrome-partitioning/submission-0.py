class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        def is_palindrome(word):
            if not word:
                return False
            l = 0
            r = len(word)-1
            while l < r:
                if word[l] != word[r]:
                    return False
                l+=1
                r-=1
            return True

        def backtrack(index, substr):  
            if index == len(s):
                res.append(substr[:])
                return                        

            for i in range(index, len(s)): 
                word = s[index:i+1]
                if is_palindrome(word):
                    substr.append(word)                    
                    backtrack(i+1, substr)
                    substr.pop()
        
        backtrack(0, [])
        return res