# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        return self.checkSymmetric(root, root)

    def checkSymmetric(self, root1, root2):
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        if root1.val != root2.val:
            return False
        return self.checkSymmetric(root1.left, root2.right) and self.checkSymmetric(root1.right, root2.left)


'''
class Solution:
    # First, i think about to solve by doing inordertraversal,
    # check the left side is equal the right side of the root.
    #         inorder=self.inorder(root)
    # print(inorder)
    def isSymmetric(self, root: TreeNode) -> bool:
        l = inorder[:inorder.index(root.val)]
        r = inorder[inorder.index(root.val)+1:]
        print(l)
        print(r)
        if l==r[::-1]:
            return True
        return False
    def inorder(self,root):
        ans=[]
        if root is None:
            return ["null"]
        l=self.inorder(root.left)
        r=self.inorder(root.right)

        return  l + [root.val] + r 

    # However, we can't solve those kinds of cases by checking the inorder traversal.
'''
''' 1
   / \
  2   2
 /   / \
2   2     '''


