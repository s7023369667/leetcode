
int cmpfunc(const int* a, const int* b){
    return *a - *b;
}

int lastStoneWeight(int* stones, int stonesSize){
    
    while (stonesSize > 1){
        qsort(stones, stonesSize, sizeof(int),cmpfunc);
        if (stones[stonesSize-1] - stones[stonesSize-2]){
            stones[stonesSize-2] = stones[stonesSize-1] - stones[stonesSize-2];
            stonesSize--;
        }else{
            stones[stonesSize-2] = 0;
            stonesSize-=2;
        }        
    }
    return  stones[0];
}
