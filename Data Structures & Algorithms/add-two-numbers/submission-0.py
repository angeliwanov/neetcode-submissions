# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:       
        # add nodes        
        h1 = l1
        h2 = l2
        prev = h1
        carry = 0

        while h1 and h2:
            total = h1.val + h2.val + carry
            carry = total // 10
            total = total % 10
            h1.val = total            
            prev = h1
            h1 = h1.next
            h2 = h2.next

        if h2:
            prev.next = h2            
        curr = h1 if h1 else h2
        
        while curr:
            total = curr.val + carry
            carry = total // 10
            total = total % 10            
            curr.val = total
            prev = curr    
            curr = curr.next

        if carry:
            prev.next = ListNode(carry)
        
        return l1
            



