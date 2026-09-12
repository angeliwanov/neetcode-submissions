class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:        
        n = len(heights)
        stack = []
        leftmost = [-1] * n
        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if stack:
                leftmost[i] = stack[-1]
            stack.append(i)
        
        stack = []
        rightmost = [n] * n
        for i in range(n-1,-1,-1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if stack:
                rightmost[i] = stack[-1]
            stack.append(i)
    
        max_area = 0
        for i in range(n):
            leftmost[i] += 1
            rightmost[i] -= 1
            max_area = max(max_area, heights[i] * (rightmost[i] - leftmost[i] + 1))
        
        return max_area