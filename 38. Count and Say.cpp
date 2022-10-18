class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i=1;i<n;i++){
            res = countAndSay(res);
        }
        return res;
    }
private:
    string countAndSay(string& s){
        string result;
        int cnt = 1;
        char currChar = s[0];
        for (int i=1;i<s.length();i++){
            if (s[i] != currChar){
                result += to_string(cnt); //convert number to string.
                result.push_back(currChar); //push char to string at back.
                cnt=1;
                currChar = s[i];
            }else{
                cnt++;
            }
        }
        result += to_string(cnt);
        result.push_back(currChar);
        return result;
    }
};
