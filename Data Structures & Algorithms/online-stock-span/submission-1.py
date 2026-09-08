class StockSpanner:

    def __init__(self):
        self.stack = [(0, float('inf'))]
        self.day = 0

    def next(self, price: int) -> int:
        self.day += 1
        while self.stack[-1][1] <= price:
            self.stack.pop()
        self.stack.append((self.day, price))
        return self.day - self.stack[-2][0]

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)