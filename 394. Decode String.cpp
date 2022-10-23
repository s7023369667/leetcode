class Solution {
public:
    
    string stringConcate(string& s, int times){
        string out;
        for (int i=0;i<times;i++){
            out.append(s);
        }
        return out;
    }
    string decodeString(string s) {
        stack<int> mulS;
        stack<string> stringS;
        mulS.push(1); //// topperString initialize multiply with 1
        stringS.push(""); ////topperString initialize to ""
        int currMul = 0;
        for (char c:s){
            if (isdigit(c)){ //deal with the couninous digits
                currMul *= 10;
                currMul += (c-'0');
            }else if (c=='['){
                mulS.push(currMul);
                stringS.push("");
                currMul = 0;
            }else if (c==']'){
                int mul = mulS.top();
                mulS.pop();
                string topString = stringS.top();
                stringS.pop();
                string decTop = stringConcate(topString, mul);
                string topperString = stringS.top();
                stringS.pop();
                stringS.push(topperString+decTop);
            }else{ 
                stringS.top().push_back(c);
            }
        }
        return stringS.top();
        
    }
};
