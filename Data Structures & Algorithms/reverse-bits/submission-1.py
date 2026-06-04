class Solution:
    def reverseBits(self, n: int) -> int:
        reversed = 0

        for i in range(31):
            reversed |= n & 1
            n >>= 1
            reversed <<= 1

        return reversed | n & 1