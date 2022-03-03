

int numberOfArithmeticSlices(int* nums, int numsSize){
    int res=0,v=0;
    for (int i=2;i<numsSize;i++){
        
        if (nums[i-1] - nums[i-2] == nums[i] - nums[i-1]){
            v++;
            res += v;
        }else{
            v = 0;
        }
    }
    return res;
}
