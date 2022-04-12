
int dir[8][2] = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1 , 1}, {0, 1}, {1, 1}};

int checkLife(int **padBoard, int r, int c){
    int cnt = 0;
    for (int i=0;i<8;i++){
        if (padBoard[r+dir[i][0]][c+dir[i][1]] == 1){
            cnt ++;
        }
    }
    if (cnt < 2 && padBoard[r][c] == 1){
        return 0;
    }else if ((cnt == 2 || cnt == 3) && padBoard[r][c] == 1){
        return 1;
    }else if (cnt == 3 && padBoard[r][c] == 0){
        return 1;
    }else if(cnt > 3 && padBoard[r][c] == 1){
        return 0;
    }
    return padBoard[r][c];
}


void gameOfLife(int** board, int boardSize, int* boardColSize){
    int** padBoard = malloc(sizeof(int*)*(boardSize+2)); 
    for (int i=0;i<boardSize+2;i++){
        padBoard[i] = calloc((*boardColSize)+2, sizeof(int));
    }
    for (int i=0;i<boardSize;i++){
        for (int j=0;j<(*boardColSize);j++){
            padBoard[i+1][j+1] = board[i][j];
        }
    }
    // for (int i=0;i<boardSize+2;i++){
    //     for (int j=0;j<(*boardColSize)+2;j++){
    //         printf("%d ", padBoard[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i=0;i<boardSize;i++){
        for (int j=0;j<*boardColSize;j++){
            board[i][j] = checkLife(padBoard, i+1, j+1);
        }
    }

}
