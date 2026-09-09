class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleet = sorted(list(zip(position, speed)))
        stack = []
        
        for p, s in fleet:
            while stack and (target - stack[-1][0]) / stack[-1][1] <= (target - p) / s:
                stack.pop()
            stack.append((p,s)) 

        return len(stack)