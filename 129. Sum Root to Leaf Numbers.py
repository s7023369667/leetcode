# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:

        def dfs(root: TreeNode, path: str, res: int) -> int:
            if not root:
                return 0
            if not root.left and not root.right:
                path += str(root.val)
                res += int(path)
                return res
            path += str(root.val)
            left = dfs(root.left, path, res)
            right = dfs(root.right, path, res)
            return left + right

        return dfs(root, '', 0)

