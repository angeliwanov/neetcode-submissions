# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:        
        pathSum = [-1000]
        
        def dfs(node):
            if not node:
                return -1000
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            pathSum[0] = max(pathSum[0], left, right, node.val + left + right)
            return max(node.val + left, node.val + right, node.val)

        return max(dfs(root), pathSum[0])

