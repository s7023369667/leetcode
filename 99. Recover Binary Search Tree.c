/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorderRecover(struct TreeNode* root, struct TreeNode** preNode, 
                                struct TreeNode** node1, struct TreeNode** node2){
    if (!root){
        return;
    }
    inorderRecover(root->left, preNode, node1, node2);
    printf("r:%d\n", root->val);
    if ((*node1) == NULL && (*preNode) && (*preNode)->val > root->val){
        *node1 = *preNode;
        printf("n1:%d\n", (*node1)->val);
    }
    if ((*node1) != NULL && (*preNode) && (*preNode)->val > root->val){
        *node2 = root;
        printf("n2:%d\n", (*node2)->val);
    }
    *preNode = root;
    printf("p:%d\n\n", (*preNode)->val);
    inorderRecover(root->right,preNode, node1, node2);
}


void recoverTree(struct TreeNode* root){
    struct TreeNode *preNode = NULL, *node1 = NULL, *node2 = NULL;

    inorderRecover(root, &preNode, &node1, &node2);
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

