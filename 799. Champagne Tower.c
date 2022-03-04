

double champagneTower(int poured, int query_row, int query_glass){
    double tower[101][101];
    for (int i=0;i<101;i++){
        for (int j=0;j<101;j++){
            tower[i][j] = 0.0;
        }
    }
    tower[0][0] = (double)poured;
    for (int r=0;r<=query_row;r++){
        for (int g=0;g<=r;g++){
            if (tower[r][g] > 1.0){
                tower[r+1][g] += (tower[r][g] - 1.0) / 2.0;
                tower[r+1][g+1] += (tower[r][g] - 1.0) / 2.0;
            }
        }
    }
    return tower[query_row][query_glass] < 1.0 ? tower[query_row][query_glass] : 1.0;
}
