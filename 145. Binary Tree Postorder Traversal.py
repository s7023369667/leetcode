# Definition for a binary tree node.
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def posorder(root, res):
            if not root:
                return res
            posorder(root.left, res)
            posorder(root.right, res)
            res.append(root.val)
            return res

        result = posorder(root, [])
        return result
