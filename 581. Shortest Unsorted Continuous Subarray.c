
int findUnsortedSubarray(int* nums, int numsSize){
    ////target : find the continuous subarray which sorted that the whole array sorted.
    //First : find the "end" from index-0, detect if there is any left > right.  
    int prev = nums[0];
    int end = -1;
    for (int i=1;i<numsSize;i++){
        // printf("(%d, %d)\n", prev, nums[i]);
        if (prev > nums[i]){
            end = i;
        }else{
            prev = nums[i];
        }
        // printf("end = %d\n", end);
    }
    //Second : find the "start" from index-last, detect if there is any left < right.  
    prev = nums[numsSize-1];
    int start = numsSize;
    for (int i=numsSize-2;i>=0;i--){
        // printf("(%d, %d)\n", prev, nums[i]);
        if (nums[i] > prev){
            start = i;
        }else{
            prev = nums[i];
        }
        // printf("start = %d\n", start);
    }
    
    return end > 0 ? end - start + 1 : 0;
}
