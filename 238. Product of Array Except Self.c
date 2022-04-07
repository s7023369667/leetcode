

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *front = malloc(sizeof(int)*(numsSize+1));
    front[0] = 1;
    for (int i=1;i<numsSize;i++){
        front[i] = nums[i-1] * front[i-1];
    }
    // for (int i=0;i<numsSize;i++){
    //     printf("%d ", front[i]);
    // }
    // printf("\n");
    int *back = malloc(sizeof(int)*(numsSize+1));
    back[numsSize-1] = 1;
    for (int i=numsSize-2;i>=0;i--){
        back[i] = nums[i+1] * back[i+1];
    }
    // for (int i=0;i<numsSize;i++){
    //     printf("%d ", back[i]);
    // }
    // printf("\n");
    int *res = malloc(sizeof(int)*(numsSize+1));
    *returnSize = numsSize;
    for (int i=0;i<numsSize;i++){
        res[i] = front[i] * back[i];
    }
    return res;
}
