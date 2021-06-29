# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        if root.left == None and root.right == None:
            #we need to minus leaf's value itself
            ##otherwise: targetSum==root.val
            targetSum -= root.val
            if targetSum == 0:
                return True
            else:
                return False
        return self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val)

















