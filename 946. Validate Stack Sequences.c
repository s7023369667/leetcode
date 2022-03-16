
bool isEmpty(int top){
    return top==-1 ? true : false;
}


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int stack[pushedSize];
    int top = -1;
    int pp = 0;
    for (int p = 0;p < pushedSize;p++){
        stack[++top] = pushed[p];
        while (!isEmpty(top) && stack[top] == popped[pp]){
            int data = stack[top--];
            pp++;
        }
        printf("%d\n", pp);
    }
    return pp == poppedSize;
}
