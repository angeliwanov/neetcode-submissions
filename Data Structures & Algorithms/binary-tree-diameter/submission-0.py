# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = [0]

        def dfs(node):
            if not node:
                return 0

            left = 0 if not node.left else 1 + dfs(node.left)
            right = 0 if not node.right else 1 + dfs(node.right)             
            diameter[0] = max(diameter[0], left + right)
            
            return max(left, right)

        dfs(root)
        return diameter[0]
