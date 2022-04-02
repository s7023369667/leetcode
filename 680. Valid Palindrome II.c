

bool isPalindrome(char *s, int *l, int *r){
    while (*l < *r){
        if (s[*l] != s[*r]){
            return false;
        }
        (*l)++;
        (*r)--;
    }
    return true;
    
}

bool validPalindrome(char * s){
    int L = 0, R = strlen(s)-1;
    
    if (!isPalindrome(s, &L, &R)){
        //we could only delete at most once.
        int forward = L+1;  //delete forward?
        int backward = R-1; //delete backward?
        
        //0:0, 0:1, 1:0 are all accept
        return isPalindrome(s, &forward, &R) || isPalindrome(s, &L, &backward); 
        
    }
    return true;
}



