/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//first
struct TreeNode* countNodes(struct TreeNode* root, int* cnt){
    if (!root){
        return NULL;
    }
    *cnt += 1;
    countNodes(root->left, cnt);
    countNodes(root->right, cnt);
    return root;
}

struct TreeNode* inorder(struct TreeNode* root, int** order, int* idx, int k){
    if (!root){
        return;
    }
    inorder(root->left, order, idx);
    (*order)[*idx] = root->val;
    *idx += 1;
    inorder(root->right, order, idx);
    return root;
}


int kthSmallest(struct TreeNode* root, int k){
    int cnt = 0;
    countNodes(root, &cnt);
    int *order = malloc(sizeof(int)*cnt);
    int idx = 0;
    inorder(root, &order, &idx);
    
    return order[k-1];
}

void inorder(struct TreeNode* root, int* idx, int k,struct TreeNode* res){
    if (!root){
        return;
    }
    inorder(root->left, idx, k, res);
    *idx += 1;
    if (*idx == k && res == NULL){
        res->val = root->val;
        return;
    }
    inorder(root->right, idx, k, res);
    return;
}

//second
int kthSmallest(struct TreeNode* root, int k){
    int idx = 0;
    struct TreeNode* res = malloc(sizeof(struct TreeNode));
    res->val = -1;
    inorder(root, &idx, k, res);
    return res->val;
}
