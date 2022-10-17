/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return NULL;
        }
        // cout << root->val << endl;
        if (root == p || root == q){
            // cout << "GET:" << root->val << endl;
            return root;
        }
        ////check if the left-subtree contains p and q
        TreeNode* leftSubNode = lowestCommonAncestor(root->left, p, q); 
        ////check if the right-subtree contains p and q
        TreeNode* rightSubNode = lowestCommonAncestor(root->right, p, q);
        // if (leftSubNode){
        //     cout << "leftSubNode:" << leftSubNode->val << endl;
        // }else{
        //     cout << "leftSubNode:" << "NULL" << endl;
        // }
        // if (rightSubNode){
        //     cout << "rightSubNode:" << rightSubNode->val << endl;
        // }else{
        //     cout << "rightSubNode:" << "NULL" << endl;
        // }
        if (leftSubNode && rightSubNode){
            return root;    ////root is LCA
        }
        return leftSubNode ? leftSubNode : rightSubNode;
    }
};
