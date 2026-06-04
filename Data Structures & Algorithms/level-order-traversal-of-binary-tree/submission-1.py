# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if not root:
            return result
        level = []
        queue = deque([root])

        while queue:
            level = []
            q_len = len(queue)
            for _ in range(q_len):
                node = queue.popleft()
                level.append(node.val)
                
                if (node.left):
                    queue.append(node.left)
                if (node.right):
                    queue.append(node.right)
            result.append(level)
        
        return result