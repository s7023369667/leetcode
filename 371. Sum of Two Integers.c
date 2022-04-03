

int getSum(int a, int b){
    while (b){
        int sum = a ^ b;  //sum without considering carry over.
        //printf("sum = %d", sum);
        b = (unsigned)(a & b) << 1; //compute carry over
        //printf(" b = %d\n", b);
        a = sum;
        /*a = 15, b=1
        sum = (14)01110 b = (2)00010 
        sum = (12)01100 b = (4)00100
        sum =  (8)01000 b = (8)01000
        sum =  (0)00000 b = (16)10000
        sum = (16)10000 b = (0)00000
        **/
    }
    return a;
}
