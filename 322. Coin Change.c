
#define MIN(a,b) ((a) < (b) ? (a):(b)) 

int coinChange(int* coins, int coinsSize, int amount){
    
    int *res = malloc(sizeof(int)*(amount+1));
    res[0] = 0;
    for (int i=1;i<amount+1;i++){
        res[i] = amount+1;
    }
    for (int i=1;i<amount+1;i++){
        for (int j=0;j<coinsSize;j++){
            if (i >= coins[j]){
                res[i] = MIN(res[i-coins[j]]+1, res[i]);
            }
        }
    }
    if (res[amount] == amount+1){
        return -1;
    }
    return res[amount];
}
