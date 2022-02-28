/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    char **res = NULL;  //result 
    int *p = nums, *q = nums+1;
    int tmp;
    while (p && p < nums + numsSize){
        tmp = *p;
        while (q < nums + numsSize && *q == tmp + 1){
            tmp = *q;
            q++;
        }
        //update returnSize && realloc **res
        *returnSize = *returnSize + 1;
        res = (char**)realloc(res, (*returnSize) * sizeof(char*));
        res[(*returnSize) - 1] = malloc(100);
        if (p + 1 == q){
            asprintf(res+(*returnSize)-1, "%d", *p);
        }else{
            asprintf(res+(*returnSize)-1, "%d->%d", *p, *(q-1));  //q is always one step futher while stopped.
        }
        p = q;
        q ++;
    }
    return res;
}
