class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0

        for i in range(len(heights)):
            start = i
            while stack and stack[-1][1] >= heights[i]:
                index, height = stack.pop()
                max_area = max(max_area, (i - index) * height)
                start = index                        
            stack.append((start, heights[i]))
    
        while stack:
            i, h = stack.pop()
            max_area = max(max_area, (len(heights) - i) * h)

        return max_area
        
