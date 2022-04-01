/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct info {
    int val;
    int index;
};

int cmpfunc(const void *a, const void *b){
    struct info a_ = *(struct info*)a;
    struct info b_ = *(struct info*)b;
    return a_.val - b_.val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct info arr[numsSize];
    for (int i=0;i<numsSize;i++){
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    qsort(arr, numsSize, sizeof(arr[0]), cmpfunc);
    // for (int i=0;i<numsSize;i++){
    //     printf("%d : %d \n", arr[i].index, arr[i].val);
    // }
    
    *returnSize = 2;
    int *res = malloc(sizeof(int)*(*returnSize));
    int left = 0, right = numsSize - 1;
    while (left <=right){
        int value = arr[left].val + arr[right].val;
        if (value == target){
            res[0] = arr[left].index;
            res[1] = arr[right].index;
            break;
        }else if (value > target){
            right--;
        }else{
            left++;
        }
    }
    return res;
}
