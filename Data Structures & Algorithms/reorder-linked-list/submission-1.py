# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = fast = head
        while fast and fast.next:
            cur = slow
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow
      
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        start = head
        end = prev

        while start and end:
            if start.next == end:
                break
            next_start = start.next
            next_end = end.next
            start.next = end            
            end.next = next_start
            start = next_start
            end = next_end
        


    