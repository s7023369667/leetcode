/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int *res = malloc(sizeof(int )* (*returnSize));
    for (int i=0;i< n+1;i++){
        int tmp_res = 0;
        int t = i;
        while (t != 0){
            tmp_res += (t%2) ;
            t = t / 2;
        }
        *(res + i) = tmp_res; 
    }
    return res;

}
