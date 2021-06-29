class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers( l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    head =ListNode()
    new=head
    carry=0
    while l1 !=None or l2 !=None or carry:
        new.next=ListNode()
        new=new.next
        if l1==None and l2==None and carry:
            carry =carry
        elif l1 != None and l2==None and carry:
            carry=carry+l1.val
        elif l1 ==None and l2 !=None and carry:
            carry=carry+l2.val
        elif l1==None and not carry:
            carry=carry+l2.val
        elif l2==None and not carry:
            carry=carry+l1.val
        else:
            a=l1.val
            b=l2.val
            carry=carry+a+b
        new.val=carry%10
        carry=carry//10  # 整除
        if l1 != None:
            l1 = l1.next
        if l2 != None:
            l2 = l2.next
    return head.next
"""
problem:
1.ListNode的存取、使用
2.尾巴是None無限迴圈問題
3.進位問題
4.多一個Node怎麼處理：
5.l1和l2長度不同判斷問題
6.最後一項進位問題
"""

def addTwoNumbers_list(l1, l2):

    invert_l1 = l1[::-1]
    invert_l2 = l2[::-1]
    ans=[]
    for i in range(len(l1)):
        if invert_l1[i]+invert_l2[i] >= 10:
            ans.append(0)
            ans[i-1]=ans[i-1]+1
        else:
            ans.append(invert_l1[i]+invert_l2[i])

    return ans[::-1]




