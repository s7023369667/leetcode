

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int*)*n);
    
    int **res = malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++){
        res[i] = calloc(n,sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int L = 0 , R = n-1, UP = 0, DOWN = n-1;
    int count = 1;
    while (L<=R && UP<=DOWN){
        for (int i = L;i<=R;i++){
            res[UP][i] = count++;
        }
        for (int i=UP+1;i<=DOWN;i++){
            res[i][R] = count++;
        }
        for (int i=R-1;i>L && UP!=DOWN;i--){
            res[DOWN][i] = count++;
        }
        for (int i=DOWN;i>UP && L!=R;i--){
            res[i][L] = count++;
        }
        L++,R--,UP++,DOWN--;
    }
    
    return res;
}
