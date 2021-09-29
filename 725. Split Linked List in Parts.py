# Definition for singly-linked list.
from typing import Optional, List
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        ##First ,counting the length of the Linkedlist
        n = 0
        curr = head
        while curr:
            n += 1
            curr = curr.next
        ans = []
        ##Second ,find how many additional NULL we need to add
        addnull = 0
        if n < k:
            addnull = k - n
            ##findout the actual part numbers
            k = k - addnull
        ##Third , starting partition and put the right number of "split_cnt" into tmp
        if n >= k and not n == 0:
            remain = n % k  ##distribute the remain to everyone
            split_member = n // k  ##the at least number we need to
            for i in range(k):
                if remain:
                    split_cnt = split_member + 1
                    remain -= 1
                else:
                    split_cnt = split_member
                count = 0
                curr = head
                while curr and count < (split_cnt - 1):
                    curr = curr.next
                    count += 1
                if curr:
                    nexx = curr.next  # keep the head
                    curr.next = None  # cut the link
                ans.append(head)
                head = nexx
                if not head:
                    break
        if addnull:
            for i in range(addnull):
                ans.append(ListNode(val=""))  # add None at end

        # print(ans)
        return ans




