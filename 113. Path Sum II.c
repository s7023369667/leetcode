/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int preOrderSumPath(struct TreeNode* root, int targetSum, int** res, int* returnSize, int** returnColumnSizes, int* tmpPath, int tmpCnt, int tmpSum){
    if (!root){
         return;
    }
    tmpPath[tmpCnt++] = root->val;
    tmpSum += root->val;
    if (!(root->left) && !(root->right)){
        if (tmpSum == targetSum){
            int *tmpClone = calloc(tmpCnt, sizeof(int));
            memcpy(tmpClone, tmpPath, sizeof(int)*tmpCnt);
            res[*returnSize] = tmpClone;
            (*returnColumnSizes)[*returnSize] = tmpCnt;
            (*returnSize)++;
        }
        printf("tmpCnt = %d, tmpSum = %d\n", tmpCnt, tmpSum);
        return;
    }
    preOrderSumPath(root->left, targetSum, res, returnSize, 
                    returnColumnSizes, tmpPath, tmpCnt, tmpSum);
    
    preOrderSumPath(root->right, targetSum, res, returnSize, 
                    returnColumnSizes, tmpPath, tmpCnt, tmpSum);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int tmpPath[5000];
    int **res = calloc(5000, sizeof(int**));
    *returnColumnSizes = calloc(5000, sizeof(int));
    *returnSize = 0;
    preOrderSumPath(root, targetSum, res, returnSize, returnColumnSizes, tmpPath, 0, 0);
    return res;    
}
