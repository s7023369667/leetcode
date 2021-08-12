# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def preorder(root, res):
            if not root:
                return res
            res.append(root.val)
            preorder(root.left, res)
            preorder(root.right, res)
            return res

        result = preorder(root, [])
        return result

