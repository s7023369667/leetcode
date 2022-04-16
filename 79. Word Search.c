


bool DFS(char** board, int row, int col, int r, int c, char* target, int len, int k){
    if (k == len){
        return true;
    }
    if (r<0 || r>row || c<0 || c>col || board[r][c] != target[k]){
        return false;
    }
    char tmp = board[r][c];
    board[r][c] = ' ';
    if (DFS(board, row, col, r+1, c, target, len,k+1)){
        return true;
    } 
    if(DFS(board, row, col, r-1, c, target, len, k+1)){
        return true;
    }
    if(DFS(board, row, col, r, c+1, target, len, k+1)){
        return true;
    }
    if(DFS(board, row, col, r, c-1, target, len, k+1)){
        return true;
    }
    board[r][c] = tmp;
    return false;

}


bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int len = strlen(word);
    int row = boardSize -1, col = *boardColSize-1;
    for (int i=0;i<=row;i++){
        for (int j=0;j<=col;j++){
            if (DFS(board, row, col, i, j, word, len, 0)){
                return true;
            }
        }
    }
    return false;
}
