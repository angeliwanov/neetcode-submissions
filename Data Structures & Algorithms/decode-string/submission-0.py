class Solution:
    def decodeString(self, s: str) -> str:
        res = []
        
        for char in s:
            if char == ']':
                decoded = ""
                while res and res[-1] != '[':
                    decoded = res.pop() + decoded
                res.pop()
                repeat = ""
                while res and res[-1].isdigit():
                    repeat = res.pop() + repeat
                res.append(decoded * int(repeat))
            else:
                res.append(char)

        return "".join(res)