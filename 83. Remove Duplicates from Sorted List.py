# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        visit=head
        s=head
        while visit!= None:
            #we only need to connect with the different value nodes.
            if s.val != visit.val:
                s.next=visit
                s=visit
            #if we visit the last node but it's value is equal as s:
            elif visit.next ==None and s.val==visit.val:
                s.next=None #which means we don't need that link.
            #Keep doing forward visit.
            visit = visit.next
        return head