/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* root){
    if (root == NULL){
        return;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    //Replace myself if i am leaf with value 0, otherwise leave it.
    return (!(root->val) && !(root->left) && !(root->right)) ? NULL : root;
}
