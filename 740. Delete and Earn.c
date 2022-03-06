

int deleteAndEarn(int* nums, int numsSize){
    int dp[10001]={};
    int max = 0;
    for (int c=0;c<numsSize;c++){
        dp[nums[c]]++;
        if (nums[c] > max){
            max = nums[c];
        }
    }
    for (int i=2;i<=max;i++){
        dp[i] = i * dp[i] + dp[i-2];
        if (dp[i -1] > dp[i]){
            dp[i] = dp[i-1];
        }
    }
    return dp[max];
}
