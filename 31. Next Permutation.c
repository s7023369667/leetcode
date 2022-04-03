
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int *nums, int begin, int end){
    while (begin<end){
        swap(&nums[begin], &nums[end]);
        begin++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int p = -1;
    for (int i=numsSize-1;i>0;i--){
        if (i==0){
            break;
        }
        if (nums[i] > nums[i-1]){
            p = i-1;
            break;
        }
    }
    
    if (p == -1){
        reverse(nums, 0, numsSize-1);
        return;
    }
    for (int i=numsSize-1;i>p;i--){
        if (nums[i] > nums[p]){
            swap(&nums[i], &nums[p]);
            reverse(nums, p+1, numsSize-1);
            return;
        }
    }    
    /** 
    [1,2,3,5,4] -> [1,2,4,3,5] 
    step1:find the position(p) that i > i-1, [1,2,"3","5",4]  
    step2:if p==-1 which means in non-decreasing order, we reverse the whole nums.
    step3:Swap from last position to p, reverse the p+1 to last**/
}
