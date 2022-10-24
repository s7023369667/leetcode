class Solution {
public:
    vector<string>arr;
    int maxx_out = 0;
    int maxLength(vector<string>& arr) {
        this->arr = arr;
        maxLength("", 0);
        return maxx_out;
    }
private:
    bool isUnique(string s){
        vector<int> v(26, 0);
        for (char c:s){
            v[c-'a']++;
            
            if (v[c-'a'] > 1){
                return false;
            }
        }
        return true;
    }
    void maxLength(string s, int position){
        if (position >= this->arr.size()){
            return;
        }
        for (int i=position;i<this->arr.size();i++){
            string currStr = s+(this->arr[i]);
            if (isUnique(currStr)){
                this->maxx_out = max(maxx_out, (int)currStr.size());
                maxLength(currStr,i+1);
            }
        }
    }
        
};
