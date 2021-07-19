# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        ADDUP = 97  #Ascii exchange
        def dfs(root, path: str, res):
            if not root:
                return ''
            if not root.left and not root.right:
                ##leaf path : add leaf itself into the path.
                path += chr(root.val + ADDUP)
                if res > path[::-1]:
                    res = path[::-1]
                return res
            path += chr(root.val + ADDUP)
            left = dfs(root.left, path, res)
            right = dfs(root.right, path, res)

            if right == '':
                ##left is one of the sub-solution.
                return left
            elif left == '':
                ##right is one of the sub-solution.
                return right
            else:
                ##general situation,return the smallest one.
                return left if left < right else right
        ##We set initialization of res to 'z'.
        return dfs(root, '', 'z')




