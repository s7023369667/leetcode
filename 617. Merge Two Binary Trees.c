/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* new_node(int val){
    struct TreeNode* newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (!root1 && !root2){
        return NULL;
    }
    int sum_vals = 0;
    if (!root1){
        if (!root2){
            sum_vals = 0;
        }else{
            sum_vals = root2->val;
        }
    }else {
        if (root2){
            sum_vals = root1->val + root2->val;
        }else{
            sum_vals = root1->val;
        }
    }
    struct TreeNode* newNode = new_node(sum_vals);
    if (!root1){
        if (!root2){
            newNode->left = mergeTrees(NULL, NULL);
        }else{
            newNode->left = mergeTrees(NULL, root2->left);
        }
    }else{
        if (!root2){
            newNode->left = mergeTrees(root1->left, NULL);
        }else{
            newNode->left = mergeTrees(root1->left, root2->left);
        }
    }
    if (!root1){
        if (!root2){
            newNode->right = mergeTrees(NULL, NULL);
        }else{
            newNode->right = mergeTrees(NULL, root2->right);
        }
    }else{
        if (!root2){
            newNode->right = mergeTrees(root1->right, NULL);
        }else{
            newNode->right = mergeTrees(root1->right, root2->right);
        }
    }
    return newNode;
}
