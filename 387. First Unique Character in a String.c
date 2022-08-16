

int firstUniqChar(char * s){
    int len = strlen(s);
    int *index = (int*)malloc(sizeof(int)*26);
    memset(index, 0, sizeof(int)*26);
    for (int i=0;i<len;i++){
        index[s[i] - 'a']++;
    }
    for (int i=0;i<len;i++){
        if (index[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}
