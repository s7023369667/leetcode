

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int j = 0;
    for (int i=0;i<numsSize;i++){
        if (nums[i]%2 == 0){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            j++;
        }
    }
    return nums;

}
