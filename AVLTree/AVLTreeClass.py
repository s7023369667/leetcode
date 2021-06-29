from AVLTree.BST import BST
from pprint import pprint
from AVLTree.AVLTreeNode import AVLTreeNode


class AVLTreeClass(BST):
    def __init__(self):
        super().__init__()
    def insert(self,key,val=None):
        self.root = self._insert(self.root,key,val)
        self.n+=1
    def _insert(self, root:AVLTreeNode, key, val=None) -> AVLTreeNode:
        if not root:
            return AVLTreeNode(key, val, bf=0)
        if key < root.key:
            leftSubRoot = self._insert(root.left,key,val)
            root.left = leftSubRoot
            leftSubRoot.parent = root
        elif key>root.key:
            rightSubRoot = self._insert(root.right,key,val)
            root.right = rightSubRoot
            rightSubRoot.parent = root
        else:
            return root
        root.height = max(self.get_height(root.left),self.get_height(root.right))+1
        root.bf = self.get_height(root.left) - self.get_height(root.right)
        return self.reblance(root)
    def reblance(self,root:AVLTreeNode)->AVLTreeNode:
        if root.bf ==2:
            if root.left.bf<0:
                #####L-R
                #root.left做left rotation
                #root做right rotation
                root.left = self.rotate_left(root.left)
                return self.rotate_right(root)
            else:
                #####L-L
                return self.rotate_right(root)
        elif root.bf == -2:
            if root.right.bf>0:
                #####R-L
                #root.right做right rotation
                #root做left rotation
                root.right = self.rotate_right(root.right)
                return self.rotate_left(root)
            else:
                #####R-R
                return self.rotate_left(root)
        else:
            #No need to rebalance.
            return root
    def rotate_right(self,root:AVLTreeNode)->AVLTreeNode:
        pivot = root.left
        tmp=pivot.right
        pivot.parent = root.parent
        root.parent=pivot
        root.left=tmp
        if tmp:
            tmp.parent = root
        if pivot.parent:
            if pivot.parent.left == root:
                pivot.parent.left = pivot
            else:
                pivot.parent.right = pivot
        root.height = max(self.get_height(root.left),self.get_height(root.right))+1
        root.bf = self.get_height(root.left)- self.get_height(root.right)
        pivot.height = max(self.get_height(pivot.left),self.get_height(pivot.right))
        pivot.bf=self.get_height(pivot.left)-self.get_height(pivot.right)
        return pivot
    def rotate_left(self,root:AVLTreeNode)->AVLTreeNode:
        pivot = root.right
        tmp=pivot.left
        pivot.parent = root.parent
        root.parent=pivot
        root.right=tmp
        if tmp:
            tmp.parent = root
        if pivot.parent:
            if pivot.parent.left == root:
                pivot.parent.left = pivot
            else:
                pivot.parent.right = pivot
        root.height = max(self.get_height(root.left), self.get_height(root.right)) + 1
        root.bf = self.get_height(root.left) - self.get_height(root.right)
        pivot.height = max(self.get_height(pivot.left), self.get_height(pivot.right))
        pivot.bf = self.get_height(pivot.left) - self.get_height(pivot.right)
        return pivot
    def get_height(self, root: AVLTreeNode) -> int:
        if not root:
            return 0
        else:
            return root.height



if __name__=="__main__":
    test = AVLTreeClass()
    test.insert(13)
    test.insert(10)
    test.insert(15)
    test.insert(5)
    test.insert(11)
    test.insert(14)
    test.insert(16)
    test.insert(4)
    test.insert(6)
    test.insert(3)
    print(test.root)







