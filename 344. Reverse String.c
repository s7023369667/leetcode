

void reverse(char *s, int start, int end){
    if (start > end){
        return;
    }
    char tmp = *(s+start);
    *(s+start) = *(s+end);
    *(s+end) = tmp;
    start++;
    end--;
    reverse(s, start, end);
}


void reverseString(char* s, int sSize){
    reverse(s, 0, sSize-1);
    
}
