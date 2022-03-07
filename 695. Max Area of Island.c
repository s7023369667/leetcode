
int checkIsland(int **grid, int rowSize, int colSize, int r, int c, int count){
    if (r<0 || r>= rowSize || c < 0 || c >= colSize || grid[r][c]== -1 || grid[r][c]==0){
        return 0;
    }
    count = 1;
    grid[r][c] = -1;
    count += checkIsland(grid, rowSize, colSize, r+1, c, count);
    count += checkIsland(grid, rowSize, colSize, r-1, c, count);
    count += checkIsland(grid, rowSize, colSize, r, c+1, count);
    count += checkIsland(grid, rowSize, colSize, r, c-1, count);
    return count;
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    for (int i=0;i<gridSize;i++){
        for (int j=0;j<*gridColSize;j++){
            if (grid[i][j] != 0 && grid[i][j] != -1){
                int count = 0;
                count = checkIsland(grid, gridSize , *gridColSize, i, j, count);
                if (count > max){
                    max = count;
                }
            }
        }
    }
    return max;
}
