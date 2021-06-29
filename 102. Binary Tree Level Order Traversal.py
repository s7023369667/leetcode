# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root:
            q = [root]
        else:
            return []
        level = []
        while q:
            l, bfs = [], []
            for node in q:
                ###l will get the all values in the level.
                l.append(node.val)
                if node.left:
                    bfs.append(node.left)
                if node.right:
                    bfs.append(node.right)
            ###Always get the level in every itervtion.
            q = bfs
            level.append(l)
        return level








