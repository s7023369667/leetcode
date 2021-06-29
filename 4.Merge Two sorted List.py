class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def mergeTwoLists(self, l1, l2) -> ListNode:
    l1_ishead = False
    if not l1 and not l2:
        return l2
    elif not l1 and l2:
        return l2
    elif l1 and not l2:
        return l1
    else:
        if l1.val <= l2.val:
            l1_ishead = True
            head = l1
        elif l1.val > l2.val:
            head = l2
    h1 = l1
    h2 = l2
    while l1 != None and l2 != None:
        if h1.val <= h2.val:
            h1 = l1.next
            l1.next = l2
        else:  # l1.val>l2.val
            h2 = l2.next
            l2.next = l1
        if l1 != None:
            l1 = h1
        if l2 != None:
            l2 = h2

    return head