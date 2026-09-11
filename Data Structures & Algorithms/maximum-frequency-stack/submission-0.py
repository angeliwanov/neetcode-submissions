class FreqStack:

    def __init__(self):
        self.idx = 0              
        self.heap = []
        self.count = defaultdict(int)

    def push(self, val: int) -> None:
        self.idx += 1         
        self.count[val] += 1               
        heapq.heappush(self.heap, (-self.count[val], -self.idx, val))
        

    def pop(self) -> int:
        freq, _, val = heapq.heappop(self.heap)
        self.count[val] -= 1
        self.idx -= 1
        return val
        
# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()