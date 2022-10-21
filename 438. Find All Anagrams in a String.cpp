class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vs(26), vp(26), ans;
        int s_size = s.size();
        int p_size = p.size();
        if (s_size < p_size){
            return {};
        }
        for (int i=0;i<p_size;i++){
            vs[s[i]-'a']++;
            vp[p[i]-'a']++;
        }
        if (vs == vp){
            ans.push_back(0);
        }
        for (int i=p_size;i<s_size;i++){
            vs[s[i-p_size]-'a']--;
            vs[s[i]-'a']++;
            if (vs == vp){
                ans.push_back(i-p_size+1);
            }
        }
        return ans;
    }
};
