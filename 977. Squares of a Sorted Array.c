/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* res = malloc(sizeof(int) * numsSize);
    //squaring
    for (int i = 0; i < numsSize; i++){
        *(nums + i) *= *(nums + i);
    }
    
    //bubble sort
    for (int i = 0; i < numsSize -1 ; i++){
        for (int j = i+1; j < numsSize; j++){
            if (*(nums + i) > *(nums + j)){
                int tmp = *(nums + i);
                *(nums + i) = *(nums + j);
                *(nums + j) = tmp;
            }
        }
        
    }
    for (int i = 0; i< numsSize;i++){
        *(res + i) = *(nums+i);
    }
return res;
}
