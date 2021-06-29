from AVLTree.TreeNode import TreeNode



class AVLTreeNode(TreeNode):
    def __init__(self, key, val=None, bf=0):
        super().__init__(key, val)
        self.key= key
        self.val= val
        self.bf=bf  #balance factor: HL-HR
        self.height=1   #height of this node
        self.left=None  #Left child pointer
        self.right=None #Right child pointer
        self.parent=None #parent of this node pointer
