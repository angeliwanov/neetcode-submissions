# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def backtrack(node, remain):
            if not node:
                return False
            
            if not node.left and not node.right:
                return remain == node.val
                        
            return backtrack(node.left, remain - node.val) or backtrack(node.right, remain - node.val)
            
        
        return backtrack(root, targetSum)