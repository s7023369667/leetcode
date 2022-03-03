

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = malloc(sizeof(int) * 2);

    // for (int i=0;i<numbersSize-1;i++){
    //     for (int j=i+1;j<numbersSize;j++){
    //         if (numbers[i]+numbers[j]==target){
    //             res[0] = i+1;
    //             res[1] = j+1;
    //             break;
    //         }
    //     }
    // }
    int L=0, R = numbersSize -1;

    while (L<R){
        if (numbers[L]+numbers[R] == target){
            res[0] = L+1;
            res[1] = R+1;
            break;
        }else if (numbers[L]+numbers[R] > target){
            R-=1;
        }else{
            L+=1;
        }
    }
    return res;
}
