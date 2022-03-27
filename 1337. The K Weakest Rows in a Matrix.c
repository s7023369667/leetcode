/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
////method 1
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *tmp = malloc(sizeof(int)* matSize);
    for (int i =0;i<matSize;i++){
        int cnt = 0;
        for (int j=0;j<*matColSize;j++){
            if (mat[i][j] == 1){
                cnt += 1;
            }
        }
        tmp[i] = cnt;
    }
    int *order = malloc(sizeof(int)* matSize);
    int *sorted_tmp = malloc(sizeof(int)* matSize);
    *returnSize = k;
    int *res = malloc(sizeof(int)* (*returnSize));

    int label;
    for (int i = 0;i<matSize;i++){
        int minVal = 101;
        for (int j = 0;j<matSize;j++){
            if (minVal > tmp[j]){
                minVal = tmp[j];
                label = j;
            }
        }
        sorted_tmp[i] = tmp[label];
        order[i] = label;
        tmp[label] = 101;
    }

    for (int i=0;i<k;i++){
        res[i] = order[i];
    }
    
return res;
}

////method 2
struct info {
    int val;
    int index;
};

int cmpfunc(const void *a, const void *b){
    struct info a_ = *(struct info*)a;
    struct info b_ = *(struct info*)b;
    return a_.val - b_.val;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    *returnSize = k;
    int *res = (int*)malloc(sizeof(int)* k);
    struct info tmp[matSize];
    int j;
    for (int i=0;i<matSize;i++){
        j = 0;
        while(j < *matColSize && mat[i][j]!=0){
            j++;
        }
        tmp[i].val = j;
        tmp[i].index = i;
    }
    
    qsort(tmp, matSize, sizeof(tmp[0]), cmpfunc);
    
    
    for (int i=0;i<k;i++){
        res[i] = tmp[i].index;
    }
    
return res;
}

