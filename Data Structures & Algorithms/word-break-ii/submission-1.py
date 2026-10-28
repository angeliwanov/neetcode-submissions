class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        res = []
        dic = set(wordDict)

        def backtrack(index, word, words, chars):                                 
            if index == len(s):       
                if chars == len(s):         
                    res.append(" ".join(words))                
                return
            
            word += s[index]                        
            if word in dic:
                words.append(word)                
                backtrack(index+1, "", words, chars + len(word))                
                words.pop()            
            backtrack(index + 1, word, words, chars)            

        backtrack(0, "", [], 0)
        return res