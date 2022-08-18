struct info{
    int val;
    int cnt;
};

int cmpfunc1(const int* a, const int* b){
    return *a - *b;
}

int cmpfunc2(const struct info* a, const struct info* b){
    return b->cnt - a->cnt;
}

int minSetSize(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmpfunc1);
    struct info table[arrSize];
    memset(table, 0, sizeof(struct info)*arrSize);
    int t = 0;
    int prev = arr[t];
    table[t].val = prev;
    table[t].cnt ++;
    for (int i=1;i<arrSize;i++){
        if (arr[i] == prev){
            table[t].cnt ++;
        }else{
            prev = arr[i];
            t++;
            table[t].val = prev;
            table[t].cnt++;
        }
    }
    qsort(table, arrSize, sizeof(struct info), cmpfunc2);
    // for (int i=0;i<arrSize;i++){
    //     printf("%d, %d\n", table[i].val, table[i].cnt);
    // }
    int mini_remove = 0;
    int size = arrSize;
    while (size > (arrSize/2)){
        size -= table[mini_remove++].cnt;
    }
    return mini_remove;
}
