

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int)*(*returnSize));
    int last[26]={0};
    //last appear
    for (int i=0;i<strlen(s);i++){
        last[s[i]-'a'] = i;
    }
    //ans:start, j:end
    /**Keep finding the maximum last appear char, until we get one equal last*/
    int j = 0;
    int ans = 0;
    for (int i=0;i<strlen(s);i++){
        j = j > last[s[i]-'a'] ? j : last[s[i]-'a'];
        if (i == j){
            *returnSize += 1;
            res = realloc(res, sizeof(int) * (*returnSize));
            res[*returnSize-1] = i - ans + 1;
            ans = i+1;
        }
    }
    return res;
}
