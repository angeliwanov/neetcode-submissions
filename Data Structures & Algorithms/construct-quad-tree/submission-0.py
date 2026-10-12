"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val=False, isLeaf=False, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':        
        zeros = sum([x.count(0) for x in grid])        
        ones = sum([x.count(1) for x in grid])
                
        if zeros and not ones:
            return Node(0, True)
        if ones and not zeros:
            return Node(1, True)

        node = Node()
        n = len(grid)//2
        tl = [x[:n] for x in grid[:n]]
        node.topLeft = self.construct(tl)
        tr = [x[n:] for x in grid[:n]]
        node.topRight = self.construct(tr)
        bl = [x[:n] for x in grid[n:]]
        node.bottomLeft = self.construct(bl)
        br = [x[n:] for x in grid[n:]]
        node.bottomRight = self.construct(br)
        
        return node
