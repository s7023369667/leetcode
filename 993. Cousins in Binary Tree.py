# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:

        def BFS(parent, queue, depth):
            if not parent:
                return
            if len(queue) == 2:
                if queue[0][0] != queue[1][0] and queue[0][1] == queue[1][1]:
                    return True
                else:
                    return False
            depth += 1
            if parent.left:
                if parent.left.val == x or parent.left.val == y:
                    queue.append([parent.val, depth])
            if parent.right:
                if parent.right.val == x or parent.right.val == y:
                    queue.append([parent.val, depth])

            if BFS(parent.left, queue, depth):
                return True
            return BFS(parent.right, queue, depth)

        return BFS(root, [], 0)

