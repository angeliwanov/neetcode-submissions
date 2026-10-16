# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:        
        if not root:
            return ""
        queue = deque([root])
        output = []

        while queue:
            length = len(queue)            
            for _ in range(length):
                node = queue.popleft()
                if not node:
                    output.append("")                  
                    continue  
                output.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
        
        return ",".join(output)
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:        
        serial = deque(data.split(","))             
        root = serial.popleft()
        if not root:
            return None
        root = TreeNode(int(root))
        queue = deque([root])

        while serial:   
            length = len(queue)         
            for _ in range(length):
                node = queue.popleft()                
                if not node:
                    continue
                left = serial.popleft()
                right = serial.popleft()
                if left:
                    node.left = TreeNode(int(left))
                    queue.append(node.left)
                if right:
                    node.right = TreeNode(int(right))
                    queue.append(node.right)

        return root


        