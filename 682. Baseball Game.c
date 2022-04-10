
int checkOperation(int *res, int top, char target){
    if (target == 'C'){
        int remove = res[top--];
    }else if (target == 'D'){
        res[++top] = res[top] * 2;
    }else if (target == '+'){
        res[++top] = res[top] + res[top-1];
    }
    return top;
}


int calPoints(char ** ops, int opsSize){
    int *res = malloc(sizeof(int)*1000);
    int top = -1;
    for (int i=0;i<opsSize;i++){
        long target = strtol(ops[i], NULL, 10);
        if (target == 0){ //not a num
            top = checkOperation(res, top, ops[i][0]);
        }else{
             res[++top] = target;
        }
    }
    int sum = 0;
    for (int i=0;i<=top;i++){
        sum += res[i];
    }
    return sum;
}
