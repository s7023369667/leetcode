
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return
        def BFS(go):
            next_q = []
            for n in range(len(go)):
                # print(go[n].val,end=' ')
                if go[n].left or go[n].right:
                    next_q.append(go[n].left)
                    next_q.append(go[n].right)
                if n != len(go) - 1:
                    go[n].next = go[n + 1]
            if next_q:
                BFS(next_q)

        BFS([root])
        return root






