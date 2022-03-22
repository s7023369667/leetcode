

char * getSmallestString(int n, int k){
    char *s = (char*)malloc(sizeof(char)*(n+1));
    for (int i=0;i<n;i++){
        s[i] = 'a';
    }
    s[n]=0;
    char tmp;
    int val;
    for (int j=n-1;j>=0;j--){
        if (k==j){
            break;
        }
        if (k - j > 26){
            tmp = 'z';
            val = 26;
        }else{
            tmp = (char)(k - j + 96);
            val = k - j;
        }
        s[j]= tmp;
        k -= val;
    }
    return s;
    
}
