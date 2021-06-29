# Definition for a binary tree node.
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = {}
        def traversal(root, deep):
            if not root:
                return
            # print(root.val)
            if not deep in res:
                res[deep] = root.val
            deep += 1
            traversal(root.right, deep)
            traversal(root.left, deep)
        traversal(root, 1)
        return list(res.values())
'''
[1,2,3,4,null,5,null,6]
       1
     /  \
    2    3
   / \  / \
  4  N 5   N
 /
6
[1,3,5,6]
'''

