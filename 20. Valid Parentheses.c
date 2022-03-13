

int push(char* stack,char c, int top){
    stack[top] = c;
    return top;
}

char pop(char* stack, int top){
    char data = stack[top];
    return data;
}

bool isEmpty(int top){
    return top == -1 ? true : false;
}

bool isRightOrder(char left, char right){
    
    if (left == '(' && right== ')'){
        return true;
    }else if (left=='[' && right==']'){
        return true;
    }else if (left=='{' && right=='}'){
        return true;
    }
    return false;
}

bool isValid(char * s){
    int top = -1;
    char stack[10001];
    int len = strlen(s);
    for (int i=0;i<len;i++){
        if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
            top = push(stack, s[i],++top);
        }else{
            if (!isEmpty(top)){
                char left = pop(stack, top--);
                if (!isRightOrder(left, s[i])){
                return false;
            }
            }else{
                return false;
            }
        }
    }
    return isEmpty(top);
}
