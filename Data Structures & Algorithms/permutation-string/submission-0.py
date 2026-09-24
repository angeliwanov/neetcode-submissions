class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        b1 = Counter(s1)        
        b2 = Counter(s2[:len(s1)])                
        
        for i in range(len(s1), len(s2)):
            if b2 == b1:
                return True
            b2[s2[i]] += 1
            b2[s2[i-len(s1)]] -= 1                      

        return b1 == b2

