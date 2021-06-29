# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal_iterative(self, root: TreeNode) -> List[int]:
        ##iterative method :
        l=[]
        stack=[]
        current = root
        while True:
            if current != None:
                stack.append(current)  ##Keep pushing Nodes inside the stack.
                current = current.left
            elif stack:
                current = stack.pop()  ##Take out the nodes one by one from stack.
                l.append(current.val)
                current = current.right
            else:
                break
        return l

    def inorderTraversal_recursive(self, root: TreeNode) -> List[int]:
        ##recursive method :
        if root is None:
            return []
        l = self.inorderTraversal_recursive(root.left)
        r = self.inorderTraversal_recursive(root.right)
        return l + [root.val] + r



