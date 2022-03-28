
int cmpfunc(const int *a, const int *b){
    return *a - *b;
}


bool search(int* nums, int numsSize, int target){
    if (numsSize == 1 && nums[0]==target){
        return true;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int left = 0, right = numsSize-1;
    
    while (left <= right){
        int mid = (left+right)/2;
        if (nums[mid] == target){
            return true;
        }
        if (nums[mid] > target){
            right = mid-1;
        } 
        if (nums[mid] < target){
            left = mid+1;
        }
    }
    return false;
}

bool search(int* nums, int numsSize, int target){
    if (numsSize == 1){
        if (nums[0]==target){
            return true;
        }else{
            return false;
        }
    }
    int double_size = numsSize*2;
    int *double_nums = malloc(sizeof(int) * double_size);
    int minn_idx = 0;
    for (int i=0;i+1<numsSize;i++){
        if (nums[i+1] < nums[i]){
            minn_idx = i+1;
            break;
        }
    }
    // for (int i=0;i<double_size;i++){
    //     printf("%d\t", i);
    // }
    // printf("\n");
    for (int i=0;i<double_size;i++){
        double_nums[i] = nums[i % numsSize];
        // printf("%d\t", double_nums[i]);
    }
    // printf("\n");
    int start = minn_idx, end = minn_idx + numsSize;
    while (start < end){
        
        int mid = start + (end - start)/2;
        // printf("(%d, %d, %d)\n", start, mid, end);
        // printf("%d\n", mid);
        if (double_nums[mid] == target){
            return true;
        }
        else if (double_nums[mid] > target){
            end = mid ;
        }
        else {
            start = mid +1;
        }
    }
    return false;
}
