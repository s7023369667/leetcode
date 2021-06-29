# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        ##Basic case: Empty linklist.
        if not head:
            return
        cnt = 0
        visit = head
        l = []
        ####Counting the nodes and recording the value into a list.
        while visit != None:
            l.append(visit.val)
            cnt += 1
            visit = visit.next
        '''k is the place we start to do the rotation,
        while accroding to the remain of dividing length of the linklist.'''
        k = k % cnt
        ##Basic case: we don't need to do anything.
        if k == 0: return head
        rotate = head
        mark = head
        done = -1
        # We are counting the movement.
        while done < cnt:
            kk = 1
            ####Rotating the back part.
            while rotate != None:
                while kk < k:
                    # Find the position to start the rotatation and "mark" it.
                    rotate = rotate.next
                    kk += 1
                mark = rotate
                rotate.val = l[done]
                rotate = rotate.next
                done += 1
            ####Rotating the front part.
            rotate = head
            while rotate != mark and done < cnt:
                rotate.val = l[done]
                done += 1
                rotate = rotate.next
        return head
