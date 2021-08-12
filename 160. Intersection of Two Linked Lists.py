# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        def _help(pA, pB, flagA, flagB):
            if not pA and not flagA:
                flagA = True
                pA = headB
            if not pB and not flagB:
                flagB = True
                pB = headA
            if pA == pB:
                return pA
            return _help(pA.next, pB.next, flagA, flagB)

        ans = _help(headA, headB, False, False)
        return ans





