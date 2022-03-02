void reverse(int* nums, int begin, int end){
    if (begin >= end){
        return;
    }
    int tmp = *(nums+begin);
    *(nums+begin) = *(nums+end);
    *(nums+end) = tmp;
    
    reverse(nums, ++begin, --end);
}

void rotate(int* nums, int numsSize, int k){
    if (numsSize < 2) return;
    k %= numsSize;
    if (k==0) return;
    
    reverse(nums, 0, numsSize-k-1);
    // for (int i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");
    reverse(nums, numsSize-k, numsSize-1);
    // for (int i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");
    reverse(nums, 0, numsSize-1);
    // for (int i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");
}
