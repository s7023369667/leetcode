int cmpfunc(const int* a, const int*b){
    return *a - *b;
}
int bagOfTokensScore(int* tokens, int tokensSize, int power){
    int score = 0;
    if (tokensSize == 0){
        return 0;
    }
    qsort(tokens, tokensSize, sizeof(int), cmpfunc);
    int L = 0;
    int R = tokensSize-1;
    while (L < R){
        if (tokens[L] <= power){
            power -= tokens[L++];
            score++;
        }else{
            if (score <= 0){
                break;
            }
            power += tokens[R--];
            score--;
        }
    }
    if (tokens[L] <= power){
        score++;
    }
    return score;
}
