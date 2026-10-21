class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        def backtrack(opening, closing, subset):
            if len(subset) == 2*n:
                res.append("".join(subset))
                return
            
            if closing:
                subset.append(")")
                backtrack(opening, closing-1, subset)
                subset.pop()
            
            if opening:
                subset.append("(")
                backtrack(opening-1, closing+1, subset)
                subset.pop()

        backtrack(n, 0, [])
        return res