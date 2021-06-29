# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        return self._help(root, targetSum, [], [])

    def _help(self, root, targetSum, l, ans):
        if not root:
            return []
        l.append(root.val)
        if root.left == None and root.right == None:
            if root.val == targetSum:
                ans.append(l)
                l = []
            else:
                l.pop()
        self._help(root.left, targetSum - root.val, l[:], ans)
        self._help(root.right, targetSum - root.val, l[:], ans)
        return ans



