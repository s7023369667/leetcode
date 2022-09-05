/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(struct Node* root, int* rowSize, int** returnColumnSizes, int depth, int**arr){
    if (root==NULL){
        return;
    }
    if (depth >= (*rowSize)){
        // We encounter a new level
        arr[*rowSize] = malloc(sizeof(int)*10001); 
        (*returnColumnSizes)[*rowSize] = 0; 
        (*rowSize)++;
    }
    arr[depth][(*returnColumnSizes)[depth]] = root->val;
    (*returnColumnSizes)[depth]++;
    for (int i=0;i<root->numChildren;i++){
        dfs(root->children[i], rowSize, returnColumnSizes, depth+1, arr);
    }
    
}



int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
     
    int** arr = malloc(sizeof(int*)*1001);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*10001);
    dfs(root, returnSize, returnColumnSizes, 0, arr);
    return arr;
    
    
}
