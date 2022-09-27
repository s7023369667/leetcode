
#define MAX(a,b) ((a>b)? a : b) 

void pprint(int *arr, int N){
    for (int i=0;i<N;i++){
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

char * pushDominoes(char * dominoes){
    int N = strlen(dominoes);
    char *res = malloc(sizeof(char)*(N+1));
    int values[N];
    memset(values, 0, sizeof(int)*N);
    
    int val = 0;
    for (int i=0;i<N;i++){
        //find "right" , from left to right
        if (dominoes[i] == 'L'){
            val = 0;
        }else if (dominoes[i] == 'R'){
            val = N;
        }else{//dominoes[i] == '.'
            val = MAX(val-1, 0); //minus yourself
        }
        values[i] += val; 
    }
    // pprint(values, N);
    val = 0;
    for (int i=N-1;i>=0;i--){
        //find "left" , from right to left
        if (dominoes[i] == 'L'){
            val = N;
        }else if (dominoes[i] == 'R'){
            val = 0;
        }else{//dominoes[i] == '.'
            val = MAX(val-1, 0); //minus yourself
        }
        values[i] -= val;
    }
    // pprint(values, N);
    
    for (int i=0;i<N;i++){
        if (values[i] < 0){
            res[i] = 'L';
        }else if (values[i] > 0){
            res[i] = 'R';
        }else{
            res[i] = '.';
        }
    }
    res[N] = '\0';
    return res;
    
}
