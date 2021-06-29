# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head: return  # nothing in head
        v = head.next
        p = head
        while v != None:
            p.val, v.val = v.val, p.val  # swap pairs
            # p always in front of v
            p = v.next
            if p != None:
                # v always next ot p
                v = p.next
            else:
                # p is None,so as v
                break
        return head

