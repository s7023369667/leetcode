# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        visit = head
        front = ListNode(0, None)
        back = ListNode(0, None)
        ##f,b is the pointer working in the front ,back part of the linked list.
        f, b = front, back
        while visit != None:
            ##Deal with the back part.
            if visit.val >= x:
                b.next = visit
                b = b.next
            ##Deal with the front part.
            else:
                f.next = visit
                f = f.next
            visit = visit.next
        b.next = None
        f.next = back.next
        return front.next

    '''
    [1,4,6,3,2,5,2]
    back:4->6->3->5
    front:1->2->2
    return fornt+back
    '''
