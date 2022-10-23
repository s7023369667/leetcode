class Solution {
public:
    stack<char> helper(string& s){
        int n = s.length();
        stack<char> st;
        for (int i=0;i<n;i++){
            if ((s[i] == '#') && (!st.empty())){
                st.pop();
            }else if(s[i] != '#'){
                st.push(s[i]);
            }
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        return helper(s)==helper(t);
    }
};
