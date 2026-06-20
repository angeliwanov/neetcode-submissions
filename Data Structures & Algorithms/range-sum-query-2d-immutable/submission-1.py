class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.prefix = []
        rows = len(matrix)
        cols = len(matrix[0])

        for row in range(rows):
            curr = [0] * (cols+1)
            for col in range(cols):
                curr[col+1] = curr[col] + matrix[row][col]
            self.prefix.append(curr)


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        total = 0
        for row in range(row1, row2+1):
            total += self.prefix[row][col2+1] - self.prefix[row][col1]
        return total


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)