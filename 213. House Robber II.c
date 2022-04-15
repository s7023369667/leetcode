#define MAX(a,b) ((a) > (b)) ? (a) : (b)



int rob(int* nums, int numsSize){
    if (numsSize == 1){
        return nums[0];
    }
    int path_a = 0, path_b = 0;
    int pre = 0;
    for (int i=0;i<numsSize-1;i++){
        int tmp = path_a;
        path_a = MAX(path_a, pre+nums[i]);
        pre = tmp;
    }
    
    pre = 0;
    for (int i=1;i<numsSize;i++){
        int tmp = path_b;
        path_b = MAX(path_b, pre+nums[i]);
        pre = tmp;
    }
    return path_a > path_b ? path_a : path_b;
}
