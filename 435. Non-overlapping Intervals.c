
struct info{
    int start;
    int end;
};

int cmpfunc(const void* a, const void *b){
    int res = ((struct info *)a)->end - ((struct info *)b)->end;  
    if (res==0){
        res = ((struct info *)a)->start - ((struct info *)b)->start;  
    }
    return res;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    
    if (intervalsSize == 0){
        return 0;
    }
    struct info *tmp = malloc(sizeof(struct info)*intervalsSize);
    for (int i=0;i<intervalsSize;i++){
        tmp[i].start = intervals[i][0];
        tmp[i].end = intervals[i][1];
    }
    
    qsort(tmp, intervalsSize, sizeof(tmp[0]), cmpfunc);
    
    // for (int i=0;i<intervalsSize;i++){
    //     printf("(%d, %d)\n", tmp[i].start,tmp[i].end);
    // }
    //count keep 
    /**
      (1,2) (1,3) (1,4) (3,4)
    s   1     1     1     3
    e   2     2     2     4
    k   1     1     1     2
    **/
    int keep = 1;
    int start = tmp[0].start;
    int end = tmp[0].end;
    for (int i=1;i<intervalsSize;i++){
        start = tmp[i].start; 
        if (start >= end){
            keep ++;
            end = tmp[i].end;
        }
        printf("start: %d ; end: %d\n", start, end);
    }    
    return intervalsSize-keep;
    
}
