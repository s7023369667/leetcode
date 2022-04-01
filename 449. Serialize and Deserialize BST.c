/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int LENGTH = 0;

void travers_cnt(struct TreeNode* root, int* cnt){
    if (!root){
        return;
    }
    *cnt+=1;
    travers_cnt(root->left, cnt);
    travers_cnt(root->right, cnt);
}

void travers_preorder(struct TreeNode* root, char** res, int *i){
    if (!root){
        return;
    }
    int tmp = root->val;
    int c = 0;
    if (tmp==0){
        res[*i][c] = tmp + '0';
        // printf("%c", res[*i][c]);
        c += 1;
    }
    while (tmp > 0){
        int remain = tmp % 10;
        tmp = tmp / 10;
        res[*i][c] = remain + '0';
        // printf("%c", res[*i][c]);
        c += 1;
    }
    // printf("|");
    res[*i][c] = '\0';
    *i = *i + 1;
    travers_preorder(root->left, res, i);
    travers_preorder(root->right, res, i);
}


/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    int cnt = 0;
    travers_cnt(root, &cnt);
    int idx = 0;
    char **res = malloc(sizeof(char*)*(cnt+1));
    for (int i=0;i<cnt+1;i++){
        res[i] = malloc(sizeof(char)*5);
    }
    travers_preorder(root, res, &idx);
    LENGTH = cnt;
    return res;    
}

struct TreeNode* newNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node -> val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertNode(struct TreeNode* root, int data){
    if (!root){
        struct TreeNode* new_node = newNode(data);
        return new_node;
    }
    if (root->val < data){
        root->right = insertNode(root->right, data);
    }else if (root->val > data){
        root->left = insertNode(root->left, data);
    }
    return root;
}
/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char** data) {
    if (!data){
        return NULL;
    }
    struct TreeNode* res = NULL;
    for (int i=0;i<LENGTH;i++){
        int j=0;
        long sum = 0;
        while (data[i][j]!='\0'){
            int val = data[i][j] - '0';
            val = val * (int)pow(10.0, j); 
            sum += val;
            j++;
        }
        res = insertNode(res, sum);
    }
    return res;
}
/**
[41, 6, 8469, 0, 22, 6336, 9177]

>>>14|6|0|22|9648|6336|7719|

>>>BST

**/
// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
