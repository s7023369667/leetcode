/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* root, char* ans, int* idx){
    if (!root){
        return;
    }
    *idx += sprintf(&ans[*idx], "%d", root->val);
    if (!(root->left) && !(root->right)){
        return;
    }else{
        *idx += sprintf(&ans[*idx], "%c", '(');
        helper(root->left, ans, idx);
        *idx += sprintf(&ans[*idx], "%c", ')');
        
        if (root->right){
            *idx += sprintf(&ans[*idx], "%c", '(');
            helper(root->right, ans, idx);
            *idx += sprintf(&ans[*idx], "%c", ')');
        }
        return;
    }
   
}

char * tree2str(struct TreeNode* root){
    int idx = 0;
    char* ans = malloc(sizeof(char)*30000);
    helper(root, ans, &idx);
    ans[idx] = '\0';
    return ans;
}
