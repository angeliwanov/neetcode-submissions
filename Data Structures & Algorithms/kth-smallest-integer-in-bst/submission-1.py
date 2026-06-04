# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        visited = []
        def inorder(node):
            if not node or len(visited) >= k:
                return
            inorder(node.left)
            visited.append(node.val)
            inorder(node.right)
        
        inorder(root)
        return visited[k-1]