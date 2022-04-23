

int randomRange(int minn, int maxx){
    unsigned seed = (unsigned)time(NULL);
    srand(seed);
    int s = rand() % maxx;
    return  s + 1;
}

char L[10001];
char coder62[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01236456789";

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    char s[27] = "http://tinyurl.com/"; // 27 + 7 + '\0'
    char *code = malloc(sizeof(char)*8);
    int start = randomRange(1, strlen(longUrl)-10);
    int i;
    for (i=start;i<start+7;i++){
        code[i%start] = coder62[longUrl[i]%62];
    }
    code[i%start] = '\0';
    strcpy(L, longUrl);
    strcat(s, code);
    return s;    
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    return L;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
