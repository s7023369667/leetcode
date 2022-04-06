
int cmpfunc(const int* a, const int* b){
    return *a - *b;
}

bool checkIn(int **arr, int size, int *t){
    if (!arr){
        return false;
    }
    for(int i=0;i<size;i++){
        int cnt = 3;
        for (int j=0;j<3;j++){
            if (arr[i][j] != t[j]){
                break;
            }else{
                cnt --;
            }
        }
        if (cnt == 0){
            return true;
        }
    }
    return false;
}

long long counting_times(long long *d, int *arr,int l, int l2, int r){
    long long tmp = 0;
    if (arr[l] == arr[l2] && arr[l]==arr[r]){
        tmp += (long long)(d[arr[l]]*(d[arr[l2]]-1)*(d[arr[r]]-2)/6);
    }else if (arr[l]==arr[l2]){
        tmp += (long long)(d[arr[l]]*(d[arr[l2]]-1)*(d[arr[r]])/2);
    }else if (arr[l]==arr[r] || arr[l2]==arr[r]){
        tmp += (long long)(d[arr[l]]*(d[arr[l2]])*(d[arr[r]]-1)/2);
    }else{
        tmp += (long long)(d[arr[l]]*(d[arr[l2]])*(d[arr[r]]));
    }
    return (long long)tmp%1000000007;
}



int threeSumMulti(int* arr, int arrSize, int target){
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    long long *d = calloc(101, sizeof(long long));
    for (int i=0;i<arrSize;i++){
        d[arr[i]]++;
    }
    int cnt = 0;
    int **dir = NULL;
    int L = 0, R = arrSize - 1;
    long long ans = 0;
    while (L<R){
        int L2 = L + 1;
        R = arrSize - 1;
        while (L2<R){
            if ((arr[L] + arr[L2] + arr[R]) == target){
                int *tmp = malloc(sizeof(int)*3);
                tmp[0] = arr[L];
                tmp[1] = arr[L2];
                tmp[2] = arr[R];
                if (!checkIn(dir, cnt, tmp)){
                    ans += counting_times(d, arr, L, L2, R);
                    cnt = cnt + 1;
                    dir = (int**)realloc(dir, sizeof(int*)*cnt);
                    dir[cnt-1] = tmp;
                    // printf("(%d, %d, %d)\n", dir[cnt-1][0], dir[cnt-1][1], dir[cnt-1][2]);
                }
                L2+=d[arr[L2]];
                R-=d[arr[R]];
            }else if (arr[L] + arr[L2] + arr[R] > target){
                R--;
            }else{
                L2++;
            }
        }
        L++;
    }
    return ans;
}
