from AVLTree.TreeNode import TreeNode


class BST:
    def __init__(self):
        self.root = None
        self.n=0
    def insert(self,key,val=None):
        node = TreeNode(key,val)
        if self.root is None:
            self.root=node
        else:
            self._insert(self.root,node)
        self.n+=1
    def _insert(self, root:TreeNode, node:TreeNode):
        if root is None:
            return
        if node.key<root.key:
            if root.left is None:
                root.left=node
            else:
                self._insert(root.left,node)
        elif node.key>=root.key:
            if root.right is None:
                root.right=node
            else:
                self._insert(root.right,node)
