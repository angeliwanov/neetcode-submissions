class Solution:
    def countBits(self, n: int) -> List[int]:
        output = []

        for i in range(n+1):
            num = i
            ones = 0
            while num:
                ones += 1
                num &= num - 1
            output.append(ones)
        
        return output