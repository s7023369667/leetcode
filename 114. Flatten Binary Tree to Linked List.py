# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self._help(root, None)

    def _help(self, root, next_node):
        if not root:
            return next_node
        left = root.left
        right = root.right

        ##左子樹永遠都接None
        root.left = None
        ##右子樹以left(原先左子樹)的root為root，且將right(原先的右子樹)的root視為下一個訪問點來繼續接
        root.right = self._help(left, self._help(right, next_node))
        print(root)
        '''
            1                 1                    1
           / \              /   \                /    \
          2   5     ->    None   2      ->     None     2
         /\    \                 /\                   /    \
        3 4     6               3  4               None     3
                                    \                     /   \
                                     5                  None   4
                                      \                     /   \
                                       6                  None   5
                                                              /   \ 
                                                            None   6
        '''
        return root





