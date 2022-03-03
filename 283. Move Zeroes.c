
void moveZeroes(int *nums, int numsSize){
    int tmp = 0;
    for (int i=0;i<numsSize;i++){
        if (nums[i]!=0){
            nums[tmp] = nums[i];
            tmp++;
        }
    }
    for (int j=tmp;j<numsSize;j++){
        nums[j] = 0;
    }
}


// void moveZeroes(int *nums, int numsSize){
//     int tmp = -1;
//     for (int i=0;i<numsSize;i++){
//         if (nums[i] == 0 && tmp==-1){
//             tmp = i;
//         }
//         if (nums[i]!=0){
//             if (tmp != -1){
//                 nums[tmp] = nums[i];
//                 nums[i] = 0;
//                 tmp ++;
//             }  
//         }
//     }
// }

// void moveZeroes(int* nums, int numsSize){
//     for (int i=0;i<numsSize-1;i++){
//         for (int j=i+1;j<numsSize;j++){
//             if (nums[i]==0){
//                 int tmp = nums[i];
//                 nums[i] = nums[j];
//                 nums[j] = tmp;
//             }
//         }
//     }
// }
