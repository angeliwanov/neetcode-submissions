class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:        
        found = [0]
        words = set(wordDict)

        for i in range(1, len(s)+1):
            curr = s[:i]             
            length = len(found)           
            for j in range(length):                
                f = found[j]
                w = curr[f:]
                if w in words:
                    if i == len(s):
                        return True                                    
                    found.append(len(curr))
                    break
        
        return False