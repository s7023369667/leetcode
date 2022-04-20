/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int *node;
    int index;
    int size;
} BSTIterator;

void inorder(struct TreeNode* root, int *node, int *size){
    if (!root){
        return;
    }
    inorder(root->left, node, size);
    node[(*size)++] = root->val; 
    inorder(root->right, node, size);
}


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = malloc(sizeof(BSTIterator));
    obj->node = malloc(sizeof(int)*10000);
    obj->index = -1;
    obj->size = 0;
    inorder(root, obj->node, &obj->size);
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->node[++(obj->index)];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->index < obj->size-1;
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
