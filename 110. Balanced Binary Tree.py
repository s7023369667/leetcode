# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if self.checkBalance(root) != -1:
            return True
        return False

    def checkBalance(self, root: TreeNode) -> int:
        ##Empty tree is heigh-balance tree
        ##left subtree is balance.
        ##right subtree is balance.
        ##The different of Height between lef and right is less than equal to 1.
        ##|HL-HR|<=1
        if root == None:
            return 0
        HL = self.checkBalance(root.left)
        HR = self.checkBalance(root.right)
        # HL,HR:Find each nodes' maxDepth
        if abs(HL - HR) > 1 or HL == -1 or HR == -1:
            # HL==-1 or HR==-1 >>>we need to do rotation.
            '''
                     1
                    / \
                   2   2
                  /     \
                 3       3
                /         \
               4           4
            '''
            return -1
        else:
            return max(HL, HR) + 1




