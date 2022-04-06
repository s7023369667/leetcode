
int cmpfunc(const int* a, const int* b){
    return *a - *b;
}


int missingNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int missing_num = -1;
    for (int i=0;i<numsSize;i++){
        if (missing_num+1 != nums[i]){
            return missing_num + 1;
        }else{
            missing_num = nums[i];
        }
    }
    return numsSize;
}


int missingNumber(int* nums, int numsSize){
    int missing_num = numsSize;
    /* 7 ^ 0 = 7
       7 ^ 7 = 0
       "XOR" could be use as sum operator without any carry*/
    for (int i=0;i<numsSize;i++){
        // printf("%d ", missing_num);
        missing_num = missing_num ^ (nums[i] ^ i);
        // printf("%d ", (nums[i] ^ i));
        // printf("%d\n", missing_num);
    }
    
    return missing_num;
}
