/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkRules(struct TreeNode *root, long low, long high){
    if (root==NULL){
        return true;
    }
    if (!(root->val > low && root->val < high)){
        return false;
    }
    //left-subtree in range [low, root->val], right-subtree in range [root->val, high]
    return checkRules(root->left, low, root->val) && checkRules(root->right, root->val, high);
}

bool isValidBST(struct TreeNode* root){
    if (root==NULL){
        return true;
    }
    //left-subtree in range [INT_MIN, root->val], right-subtree in range [root->val, INT_MAX]
    return checkRules(root->left, LONG_MIN, root->val) && checkRules(root->right, root->val, LONG_MAX);
}
