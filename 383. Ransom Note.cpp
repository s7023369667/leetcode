class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mpM;
        for (char c:magazine){
            mpM[c]++;
        }
        for (int i=0;i<ransomNote.size();i++){
            if (mpM[ransomNote[i]] <= 0){
                return false;
            }else{
                mpM[ransomNote[i]]--;
            }
        }
        return true;
    }
};
