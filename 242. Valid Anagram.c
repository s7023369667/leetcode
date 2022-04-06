
int cmpfunc(const char* s, const char* t){
    return *s - *t;
}

bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)){
        return false;
    }
    qsort(s, strlen(s), sizeof(char), cmpfunc);
    qsort(t, strlen(t), sizeof(char), cmpfunc);
    for (int i=0;i<strlen(s);i++){
        if (s[i] != t[i]){
            return false;
        }
    }    
    return true;
}

bool isAnagram(char * s, char * t){
    
    qsort(s, strlen(s), sizeof(char), cmpfunc);
    qsort(t, strlen(t), sizeof(char), cmpfunc);
      
    return !strcmp(s, t);
}
