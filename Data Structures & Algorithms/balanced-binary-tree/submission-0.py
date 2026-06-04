# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(node):
            if not node:
                return [0, True]
            
            l_h, l_b = dfs(node.left)
            r_h, r_b = dfs(node.right)
            height = 1 + max(l_h, r_h)
            balanced = abs(l_h - r_h) <= 1 and l_b and r_b

            return [height, balanced]
        
        return dfs(root)[1]