class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right

def insertNode(root,key):
    if key==None:
        return
    if root==None:
        return TreeNode(val=key)
    ###insert node and keep it be the binary tree.
    if root.val > key:
        root.left = insertNode(root.left,key)
    elif root.val < key:
        root.right = insertNode(root.right,key)
    return root
def isValidBST(root:TreeNode):
    ###Method:找做邊最大和右邊最小的，如果右邊最小能大於左邊最大，則是BST
    queue = [root]
    while len(queue)>0:
        stack = []




if __name__ == '__main__':
    root1 = None
    root1 = insertNode(root1, 5)
    root1 = insertNode(root1, 1)
    root1 = insertNode(root1, 4)
    root1 = insertNode(root1, None)
    root1 = insertNode(root1, None)
    root1 = insertNode(root1, 3)
    root1 = insertNode(root1, 6)

    print(root1)

