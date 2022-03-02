

bool isSubsequence(char * s, char * t){
    char *ptr_s = s, *ptr_t = t;
    if (!*ptr_s){
        return true;
    }
    while (*ptr_t){
        if (*(ptr_s) == *(ptr_t)){
            ptr_s ++;
            if (!*ptr_s){
                return true;
            }
        }
        ptr_t ++;
    }
    return false;
}
