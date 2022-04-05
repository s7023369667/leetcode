
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    
    int res = 0;
    int L = 0, R = heightSize-1;
    while (L<R){
        int w = R - L;
        int h;
        if (height[L] < height[R]){
            h = height[L++];
        }else{
            h = height[R--];
        }
        res = MAX(w*h, res);
    }
    return res;
           
}
