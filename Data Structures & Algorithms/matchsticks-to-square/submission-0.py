class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:      
        if len(matchsticks) < 4:
            return False
        total = sum(matchsticks)        
        if total % 4 != 0:
            return False
        side = total // 4        
        if max(matchsticks) > side:
            return False
        
        def backtrack(sides, index):              
            if index == len(matchsticks):
                return sum(sides) == total * 3 / 4            

            for i in range(index, len(matchsticks)):                
                stick = matchsticks[i]
                if i > index and stick == matchsticks[i-1]:
                    continue
                for j in range(3):                    
                    if sides[j] + stick <= side:
                        sides[j] += stick         
                        if backtrack(sides, i+1):
                            return True
                        sides[j] -= stick                                     
                        
            return False

        return backtrack([0] * 3, 0)