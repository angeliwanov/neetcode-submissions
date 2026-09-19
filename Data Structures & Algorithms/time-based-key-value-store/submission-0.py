class TimeMap:

    def __init__(self):
        self.store = dict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        self.store[key].append((timestamp, value))
        self.store[key].sort()

    def get(self, key: str, timestamp: int) -> str:               
        res = ""
        if key not in self.store:
            return res
        l = 0
        r = len(self.store[key]) - 1

        while l <= r:
            m = l + (r-l) // 2        
            if self.store[key][m][0] <= timestamp:
                res = self.store[key][m][1]
                l = m + 1
            else:
                r = m - 1                            

        return res

