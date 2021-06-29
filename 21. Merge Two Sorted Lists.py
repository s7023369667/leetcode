# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # idea is Merge sort

        # creat a dummy node(we don't even use it)
        tempNode = ListNode(0)
        tail = tempNode
        while 1:
            # l1 is empty tail connect with l2
            if not l1:
                tail.next = l2
                break
            # l2 is empty tail connect with l1
            elif not l2:
                tail.next = l1
                break
            # each iteration tail will connect with one node
            elif l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        return tempNode.next












