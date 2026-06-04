# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        while (len(lists) > 1):
            tmp = []
            for i in range(0, len(lists), 2):
                lst1 = lists[i]
                lst2 = lists[i+1] if i+1 < len(lists) else None

                tmp.append(self.merge(lst1, lst2))
            lists = tmp

        return lists[0] if lists else None
    
    def merge(self, lst1, lst2):
        head = ListNode()
        curr = head

        while (lst1 and lst2):
            if lst1.val < lst2.val:
                curr.next = lst1
                lst1 = lst1.next
            else:
                curr.next = lst2
                lst2 = lst2.next
            curr = curr.next
        
        curr.next = lst1 if lst1 else lst2

        return head.next
        