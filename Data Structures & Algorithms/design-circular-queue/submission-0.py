class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
    
class MyCircularQueue:

    def __init__(self, k: int):
        self.count = 0
        self.capacity = k
        curr = self.front = self.rear = ListNode(-1)        
        for _ in range(k-1):
            curr.next = ListNode(-1)
            curr = curr.next
        curr.next = self.front            

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False     
        if self.isEmpty():
            self.rear.val = value
            self.count += 1
            return True
        self.rear = self.rear.next    
        self.rear.val = value        
        self.count += 1        
        return True


    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front.val = -1
        self.count -= 1      
        if not self.isEmpty():
            self.front = self.front.next  
        return True

    def Front(self) -> int:
        return self.front.val

    def Rear(self) -> int:
        return self.rear.val

    def isEmpty(self) -> bool:
        return self.count == 0

    def isFull(self) -> bool:
        return self.capacity == self.count


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()