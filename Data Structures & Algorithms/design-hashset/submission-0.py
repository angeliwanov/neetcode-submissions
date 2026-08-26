class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyHashSet:

    def __init__(self):
        self.hashset = [None] * 10000

    def add(self, key: int) -> None:
        if self.contains(key):
            return
        hash = key%10000
        if not self.hashset[hash]:
            self.hashset[hash] = ListNode(key)
        else:
            curr = self.hashset[hash]
            while curr and curr.next:
                curr = curr.next
            curr.next = ListNode(key)

    def remove(self, key: int) -> None:
        if not self.contains(key):
            return
        hash = key%10000
        prev = None        
        curr = self.hashset[hash]       
        while curr and curr.val != key:
            prev = curr
            curr = curr.next
        if not prev:
            self.hashset[hash] = curr.next if curr else None
        else:
            prev.next = curr.next if curr else None

    def contains(self, key: int) -> bool:
        hash = key % 10000
        curr = self.hashset[hash]
        if not curr:
            return False
        while curr and curr.val != key:
            curr = curr.next
        return curr.val == key if curr else False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)