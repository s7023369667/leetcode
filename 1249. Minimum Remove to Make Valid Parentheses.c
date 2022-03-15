

char * minRemoveToMakeValid(char * s){
    int len = strlen(s);
    int lc = 0, rc = 0;
    /**start form end, remove redundent '('**/
    for (int i=len;i>=0;i--){
        if (s[i]=='('){
            lc ++;
        }
        if (s[i]==')'){
            rc++;
        }
        if (lc > rc){
            s[i] = 0;  // ASCII(0) >> "\0"
            lc--;
        }
    }
    lc = 0, rc = 0;
    /**start form front, remove redundent ')'**/
    int ptr = 0; 
    for (int i=0;i<len;i++){
        if (s[i]=='('){
            lc ++;
        }
        if (s[i]==')'){
            rc++;
        }
        if (lc < rc){
            rc--;
        }else if (s[i]){    //s[i]!= '\0' add into result
            s[ptr++] = s[i];
        }
    }
    s[ptr] = 0; // add end character
    return s;
}
