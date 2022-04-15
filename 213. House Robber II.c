#define MAX(a,b) ((a) > (b)) ? (a) : (b)



int rob(int* nums, int numsSize){
    if (numsSize == 1){
        return nums[0];
    }
    int path_a = 0, path_b = 0;
    int prepre = 0;
    for (int i=0;i<numsSize-1;i++){
        int pre = path_a;
        path_a = MAX(path_a, prepre+nums[i]);
        prepre = pre;
    }
    
    prepre = 0;
    for (int i=1;i<numsSize;i++){
        int pre = path_b;
        path_b = MAX(path_b, prepre+nums[i]);
        prepre = pre;
    }
    return path_a > path_b ? path_a : path_b;
}
