# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import List, Optional


class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:

        def b_bst(root, c):
            # right
            if preorder[c] > root.val:
                if root.right == None:
                    root.right = TreeNode(preorder[c])
                else:
                    b_bst(root.right, c)
            # left
            else:
                if root.left == None:
                    root.left = TreeNode(preorder[c])
                else:
                    b_bst(root.left, c)

        root = TreeNode(preorder[0])
        for c in range(1, len(preorder)):
            b_bst(root, c)
        return root




