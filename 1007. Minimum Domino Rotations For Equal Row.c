

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    
    int table[7]={0};
    for (int i=0;i<topsSize;i++){
        table[tops[i]]++;
        table[bottoms[i]]++;
    }
    int max = 0, target;
    for (int i=1;i<7;i++){
        if (max < table[i]){
            max = table[i];
            target = i;
        }
    }
    printf("%d\n", target);
    int t_cnt = 0, b_cnt = 0;
    for (int i=0;i<topsSize;i++){
        if (tops[i] == target || bottoms[i] == target){
            if (tops[i] == bottoms[i]){
                continue;
            }
            if (tops[i] == target){
                b_cnt++;
            }
            if (bottoms[i] == target){
                t_cnt++;
            }
        }
        if (tops[i] != target && bottoms[i] != target){
            return -1;
        }
    }
    
    return t_cnt > b_cnt ? b_cnt : t_cnt;
    
}
