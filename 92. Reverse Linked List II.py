# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        cnt = 1
        start = head
        last = None  # saving the remaining nodes after we started the algorithm.
        previous = None  # saving the previous node befort we start the algorithm.
        while cnt != left:
            ##find the left position...
            cnt += 1
            previous = start
            start = start.next
        tail = start  # saving the tail node for the head of the remaining nodes
        result, last = self.algorithm(start, None, last, cnt, right)
        tail.next = last
        if previous:
            previous.next = result
        else:
            head = result
        return head

    def algorithm(self, curr, prev, last, cnt, right):
        ##reverse algorithm
        if not curr:
            return prev, last
        if cnt > right:
            last = curr
            return prev, last
        nex = curr.next
        curr.next = prev
        prev = curr
        cnt += 1
        prev, last = self.algorithm(nex, prev, last, cnt, right)
        return prev, last






