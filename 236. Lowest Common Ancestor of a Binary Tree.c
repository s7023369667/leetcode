/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isDescendant(struct TreeNode* root, int target){
    if (!root){
        return 0;
    }
    return (root->val == target) || isDescendant(root->left, target) || isDescendant(root->right, target);
}

void findLCA(struct TreeNode* root,struct TreeNode** ans , int p, int q){
    if (!root){
        return;
    }
    findLCA(root->left, ans, p, q);
    findLCA(root->right, ans, p, q);
    if (*ans!= NULL){
        //find the lowest common 
        return;
    }
    if (isDescendant(root, p) && isDescendant(root, q)){
        printf("%d ", root->val);
        *ans = root;
    }
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode** ans = malloc(sizeof(struct TreeNode*));
    *ans = NULL;
    findLCA(root, ans, p->val, q->val);
    
    return *ans;
}
