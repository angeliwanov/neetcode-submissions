# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:        
        def reverse(start):   
            curr = start
            for _ in range(k):
                if not curr:
                    return start
                curr = curr.next
                                                             
            prev = None
            curr = start

            for _ in range(k):                
                nextNode = curr.next
                curr.next = prev
                prev = curr
                curr = nextNode
                        
            start.next = reverse(curr)
            return prev
        
        return reverse(head)

        
            
        
        

