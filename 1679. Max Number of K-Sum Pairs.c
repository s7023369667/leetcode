

int cmpfunc(const int* a, const int* b){
    return *a - *b;
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int L = 0, R = numsSize-1;
    int ans = 0;
    while (L<R){
        int tmp = nums[L] + nums[R];
        if (tmp == k){
            ans ++;
            L++;
            R--;
        }else if (tmp > k){
            R--;
        }else{
            L++;
        }
    }
    return ans;

}
