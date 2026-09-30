# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow = ListNode(0, head)
        fast = head

        for _ in range(n):
            fast = fast.next
        
        while fast:
            slow = slow.next
            fast = fast.next

        popped = slow.next
        slow.next = slow.next.next
        return slow.next if popped == head else head