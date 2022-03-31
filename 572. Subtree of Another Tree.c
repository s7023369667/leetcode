/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool check(struct TreeNode* curr, struct TreeNode* subCurr){
    if (!curr && !subCurr){
        return true;
    }
    if (!curr || !subCurr){
        return false;
    }
    if (curr->val == subCurr->val){
        if (check(curr->left, subCurr->left) && check(curr->right, subCurr->right)){
            return true;
        }
    }
    return false;
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    
    if (!root && !subRoot){
        return true;
    }
    if (root){
        return (check(root, subRoot) ||isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)); 
    }
    return false;  
}
