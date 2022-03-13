

bool isPowerOfTwo(int n){
    
    int cnt = 0;
    while (n > 0){
        /*2的次方只有最低位是1且只有一個1*/
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt == 1;
}
