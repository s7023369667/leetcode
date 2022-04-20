/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* node, int* cnt){
    if (!root){
        return;
    }
    inorder(root->left, node, cnt);
    node[(*cnt)++] = root->val;
    inorder(root->right, node, cnt);
}


typedef struct {
    int *node;
    int index;
    int cnt;
    
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *tree = malloc(sizeof(BSTIterator));
    tree->node = (int*)malloc(sizeof(int)*10000);
    tree->index = -1;
    tree->cnt = 0;
    inorder(root, tree->node, &tree->cnt);
    return tree;
    
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->node[++(obj->index)];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->index < obj->cnt-1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->node);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
