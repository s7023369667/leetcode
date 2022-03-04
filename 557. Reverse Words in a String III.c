

void reverse_recursive(char* sub_str, int start, int end){
    if (start > end){
        return;
    }
    char tmp = *(sub_str+start);
    *(sub_str+start) = *(sub_str+end);
    *(sub_str+end) = tmp;
    start++;
    end--;
    reverse(sub_str, start, end);
}

void reverse(char* sub_str, int start, int end){
    while (start <= end){
        char tmp = *(sub_str+start);
        *(sub_str+start) = *(sub_str+end);
        *(sub_str+end) = tmp;
        start++;
        end--;
    }
}


char * reverseWords(char * s){
    int end = 0, start = 0;
    int size = 0;
    char* sub_str = malloc(sizeof(char) * (size));
    while (s[end] != '\0'){
        if ((s[end] ==' ')){
            // reverse_recursive(sub_str, 0, size-1);
            reverse(sub_str, 0, size-1);
            int j = 0;
            for (int i =start;i<start+size;i++){
                s[i] = sub_str[j];
                j++;
            }
            start = start+size + 1;
            sub_str = NULL;
            size = 0;
        }else{
            size ++;
            sub_str = realloc(sub_str,sizeof(char) * (size));
            sub_str[size-1] = s[end];
        }
        end ++;
    }
    reverse(sub_str, 0, size-1);
    // reverse_recursive(sub_str, 0, size-1);
    int j = 0;
    for (int i =start;i<start+size;i++){
        s[i] = sub_str[j];
        j++;
    }
return s;
}
