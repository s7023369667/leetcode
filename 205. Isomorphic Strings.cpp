class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> Smap2T(256, -1);
        vector<int> Tmap2S(256, -1);

        
        for (int i=0;i<s.size();i++){
            if (Smap2T[s[i]] != Tmap2S[t[i]]){
                return false;
            }
            Smap2T[s[i]] = i;
            Tmap2S[t[i]] = i;
        }
        return true; 
    }
};
