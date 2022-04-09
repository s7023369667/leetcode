/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct info {
    int val;
    int times;  
};

int cmpfunc1(const int* a, const int* b){
    return *a - *b;
}

int cmpfunc2(const struct info* a, const struct info* b){
    return b->times - a->times;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc1);
    struct info table[numsSize];
    memset(table, 0, sizeof(struct info)*numsSize);
    int prev = nums[0];
    table[0].val = prev;
    table[0].times++;
    int j = 0;
    for (int i=1;i<numsSize;i++){
       if (prev == nums[i]){
           table[j].times++;
       }else{
           prev = nums[i];
           j++;
           table[j].val = prev;
           table[j].times++;
       }
    }
    qsort(table, numsSize, sizeof(struct info), cmpfunc2);
    *returnSize = k;
    int *res = malloc(sizeof(int)*(*returnSize));
    for (int i=0;i<*returnSize;i++){
        res[i] = table[i].val;
    }
    
    return res;
}
