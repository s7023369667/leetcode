int compareVersion(char * version1, char * version2){
    
    
    
    
    while (* version1 || * version2){
        int ver1num = 0;
        while (*version1 && *version1 != '.'){
            ver1num = ver1num * 10 + (*(version1++) - '0');
        }
        int ver2num = 0;
        while (*version2 && *version2 != '.'){
            ver2num = ver2num * 10 + (*(version2++) - '0');
        }
        if (ver1num > ver2num){
            return 1;
        }
        if (ver1num < ver2num){
            return -1;
        }
        if (*version1){
            version1++;
        }
        if (*version2){
            version2++;
        }
    }
    
    return 0;
}
