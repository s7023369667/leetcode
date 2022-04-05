#define MAX(a,b) ((a) > (b) ? (a) : (b))

int lengthOfLIS(int* nums, int numsSize){
    int max_res = 1;
    int *res = malloc(sizeof(int)*numsSize);
    for (int i=0;i<numsSize;i++){
        res[i] = 1;
    }
    for (int i=1;i<numsSize;i++){
        for (int j=0;j<i;j++){
            if (nums[i] > nums[j]){
                res[i] = MAX(res[j]+1, res[i]);
                if (max_res < res[i]){
                    max_res = res[i];
                }
            }
        }
    }
    return max_res;
}
