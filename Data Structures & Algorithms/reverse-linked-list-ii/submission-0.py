# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        prev = None
        curr = head

        for _ in range(left-1):
            prev = curr
            curr = curr.next
        
        start = prev
        end = curr
        
        for _ in range(right - left + 1):
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        
        
        end.next = curr
        if start:
            start.next = prev
            return head
        else:
            return prev
        

        
        

