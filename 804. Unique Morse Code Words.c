
int cmpfunc(const char* a, const char* b){
    return strcmp(a, b);
}


int uniqueMorseRepresentations(char ** words, int wordsSize){
    
    
    char table[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                    ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                    ".--","-..-","-.--","--.."};
    
    for (int i=0;i<wordsSize;i++){
        int len = strlen(words[i]);
        char *s = (char*)malloc(sizeof(char)*(100));
        int idx = 0;               
        for (int j=0;j<len;j++){
            int l = strlen(table[words[i][j] - 'a']);

            for (int k=0;k<l;k++){
                s[idx++] = table[words[i][j] - 'a'][k];
            }  
        }
        s[idx] = '\0';
        words[i] = s;        
    }
    
    qsort(words, wordsSize, sizeof(char*), cmpfunc);
    int ans = wordsSize;
    for (int i=1;i<wordsSize;i++){
        if (!strcmp(words[i-1], words[i])){
            ans --;
        }
    }
    return ans;

}
