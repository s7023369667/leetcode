/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, acalssume ler calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int row = gridSize;
    int col = *gridColSize;
    *returnSize = gridSize;
    *returnColumnSizes = malloc(sizeof(int)*row);
    for (int i=0;i<row;i++){
        (*returnColumnSizes)[i] = col;
    }
    int **res = malloc(sizeof(int*)*row);
    for (int i=0;i<row;i++){
        res[i] = malloc(sizeof(int)*col);
    }            
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            int tmp = j + i*col + k;
            tmp %= gridSize*(*gridColSize);
            int r = tmp / (*gridColSize);
            int c = tmp % (*gridColSize);
            res[r][c] = grid[i][j];
        }
    }
return res;
}
