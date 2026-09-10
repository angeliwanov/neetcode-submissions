class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path = path.split('/')
        
        for char in path:
            if char == "." or not char:
                continue
            elif char == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(char)
            
        
        return "/" + "/".join(stack)