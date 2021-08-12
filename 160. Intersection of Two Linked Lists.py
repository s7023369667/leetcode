# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        def _help(pA, pB, flagA, flagB):
            ##4 1 8 4 5|5 6 1 8 4 5
            ##5 6 1 8 4 5|4 1 8 4 5
            '''
            每次都比pA和pB，因為是兩條不同的linked list
            所以如果在比較時就算找到pA和pB都是1->8->4->5->None一樣的，但Nond 1的位置是不同的
            所以會找到交集點是是Node 8
            '''
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





