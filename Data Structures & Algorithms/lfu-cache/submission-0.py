class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.lru = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.lru:
            return -1
        self.lru[key][0] += 1
        self.lru.move_to_end(key)
        return self.lru[key][1]

    def put(self, key: int, value: int) -> None:
        if key in self.lru: 
            self.lru[key][0] += 1
            self.lru[key][1] = value
            self.lru.move_to_end(key)
        else:
            if len(self.lru) == self.capacity:
                candidates = []
                i = 0
                for k,v in self.lru.items():  
                    candidates.append([v[0], i, k])
                    i += 1
                candidates.sort()                
                del self.lru[candidates[0][2]]
            self.lru[key] = [1, value]
            self.lru.move_to_end(key)


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)