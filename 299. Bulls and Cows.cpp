class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp;
        int A = 0, B = 0;
        int n = secret.size();
        for (int i=0;i<n;i++){
            if (secret[i] == guess[i]){
                A++;
            }else{
                mp[secret[i]]++;
            }
            
        }
        for (int i=0;i<n;i++){
            if (secret[i] != guess[i]){
                if (mp[guess[i]] > 0){
                    B++;
                    mp[guess[i]]--;
                }
            }
        }        
        return to_string(A) + "A" + to_string(B) + "B";;
    }
};
