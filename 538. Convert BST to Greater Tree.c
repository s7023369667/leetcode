/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumGreater(struct TreeNode* root, int passVal){
    if (!root){
        return passVal;
    }
    root->val += sumGreater(root->right, passVal);
    return sumGreater(root->left, root->val);
}


struct TreeNode* convertBST(struct TreeNode* root){
    if (!root){
        return NULL;
    }
    sumGreater(root, 0);
    return root;
}
