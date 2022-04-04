

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct info {
    int val;
    int freq;
};

int cmpfunc1(const int* a, const int* b){
    return *a - *b;
}

int cmpfunc2(const struct info* a, const struct info* b){    
    return b->freq - a->freq;
}


int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = k;
    int *res = (int*)malloc(sizeof(int)*(*returnSize));
    if (numsSize == 1){
        return nums;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc1);
    struct info dir[numsSize];
    memset(dir, 0, sizeof(struct info)*numsSize); //make hashable
    int count = 1;
    dir[0].val = nums[0];
    dir[0].freq++;
    for (int i=1;i<numsSize;i++){
        if (dir[count-1].val == nums[i]){
            dir[count-1].freq++;
        }else{
            count++;
            dir[count-1].val = nums[i];
            dir[count-1].freq++;
        }
    }    
    // for (int i=0;i<numsSize;i++){
    //     printf("%d:%d\n", d[i].val, d[i].freq);
    // }
    qsort(dir, numsSize, sizeof(dir[0]), cmpfunc2);
    for (int i=0;i<*returnSize;i++){
        res[i] = dir[i].val;
    }
    return res;
}








