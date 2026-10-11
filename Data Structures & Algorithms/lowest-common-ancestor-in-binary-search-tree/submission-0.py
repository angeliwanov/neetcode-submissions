# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, node):
        if not node:
            return False
        if node == p or node == q:
            return True
        return self.dfs(node.left) or self.dfs(node.right)

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return None
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        curr = root == p or root == q

        if (curr and left) or (curr and right) or (left and right):
            return root        
        return self.lowestCommonAncestor(root.left, p, q) or self.lowestCommonAncestor(root.right, p, q)
        
