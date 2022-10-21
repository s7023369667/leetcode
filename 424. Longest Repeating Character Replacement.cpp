class Solution {
public:
    int characterReplacement(string s, int k) {
        //tricky sliding window solution
        vector<int> vs(26);
        int n = s.length();
        
        int first = 0, last = 0, result = 0;
        int max_freq = INT_MIN;
        
        for (int i=0;i<n;i++){
            max_freq = max(max_freq, ++vs[s[i]-'A']);
            
            if ((last - first + 1 - max_freq) > k){
                vs[s[first++]-'A']--;
            }
            result = max(result, last-first+1);
            last++;
        }
        return result;
    }
};
