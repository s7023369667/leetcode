

int characterReplacement(char * s, int k){
    
    int len = strlen(s);
    if (len == 0){
        return 0;
    }
    int max = 0;
    for (int i=0;i<len-1;i++){
        int kk = k;
        int j = i+1;
        while (j < len){
            if (s[i] != s[j]){
                kk--;
            }
            if (kk<0){
                break;
            }
            j++;
        }
        // printf("i=%d, j=%d\n", i, j);
        // printf("kk=%d\n", kk);
        int tmp;
        if (j==len && kk>=0){
            if (kk > i){
                tmp = j-i+ i;
            }else{
                tmp = j-i + kk;
            }
            
        }else{
            tmp = j-i;
        }
        if (max < tmp){
            max = tmp;
        }
        // printf("max = %d\n", max);
    }
    
return max;
}
