class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for asteroid in asteroids:
            if asteroid > 0:
                stack.append(asteroid)
            else:                
                while stack and stack[-1] > 0:                                            
                    if stack[-1] < abs(asteroid):
                        stack.pop()
                    elif stack[-1] == abs(asteroid):                        
                        stack.pop()
                        asteroid = 0
                        break
                    else:
                        asteroid = 0
                        break
                if asteroid:                        
                    stack.append(asteroid)
                    
        return stack