# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def generateTrees(self, n: int) :#-> List[TreeNode]
        return self._construct(1, n)

    def _construct(self, start, end):
        T = []
        ##Filtering the situation that
        if start > end:
            # print(start)
            # print(end)
            T.append(None)
            return T
        for i in range(start, end + 1):
            ##Base on the ith root,constructure the left subtree and right subtree
            left_sub = self._construct(start, i - 1)
            right_sub = self._construct(i + 1, end)

            ##Connecting all the nodes in left subtree  and right subtree
            for j in range(len(left_sub)):
                left = left_sub[j]
                print(left)
                for k in range(len(right_sub)):
                    right = right_sub[k]
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    T.append(root)
        return T












