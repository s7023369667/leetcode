/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void inorder(struct TreeNode* root, struct TreeNode** newRoot){
    if (!root){
        (*newRoot)->left = NULL;
        (*newRoot)->right = NULL;
        return;
    }
    inorder(root->left, newRoot);
    (*newRoot)->left = NULL;
    (*newRoot)->right = root;
    *newRoot = (*newRoot)->right;
    inorder(root->right, newRoot);
    return;
}


struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* newRoot = malloc(sizeof(struct TreeNode));
    struct TreeNode* res = newRoot;
    inorder(root, &newRoot);
    
    return res->right;
}
