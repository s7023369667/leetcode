# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) :
        # BFS:
        visit = []
        if root == None:
            return visit
        queue = [root]
        print(len(queue))
        while len(queue) != 0:
            visit.append([node.val for node in queue])
            q = []
            # Doing level order traversal.
            for node in queue:
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            # Update queue by q
            queue = q
            print(len(queue))
        print(visit)
        # ans=[]
        # for i in range(len(visit)-1,-1,-1):
        #     ans.append(visit[i])
        return visit[::-1]













