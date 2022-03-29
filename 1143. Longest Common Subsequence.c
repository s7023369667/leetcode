#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int longestCommonSubsequence(char * text1, char * text2){
    int t1 = strlen(text1);
    int t2 = strlen(text2);
    int **dp = (int**)malloc(sizeof(int*)*(t1+1));
    for (int i=0;i<t1+1;i++){
        dp[i] = (int*)malloc(sizeof(int)*(t2+1));
    }
    for (int j=0;j<=t2;j++){
        dp[0][j] = 0;
    }
    for (int i=0;i<=t1;i++){
        dp[i][0] = 0;
    }
    for (int i=1;i<=t1;i++){
        for (int j=1;j<=t2;j++){
            if (text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[t1][t2];
}
