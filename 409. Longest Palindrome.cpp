class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char c:s){
            mp[c]++;
        }
        int len=0, carry=0;
        for (auto x:mp){
            if (x.second %2 == 1){
                len += (x.second -1);
                carry = 1;
            }else {
                len += x.second;
            }
            
        }
        return len + carry;
    }
};
