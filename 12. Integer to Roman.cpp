class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> vRoman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> vNum = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        while (num > 0){
            for (int i=0;i<vNum.size();i++){
                if (num >= vNum[i]){
                    res +=vRoman[i];
                    num -= vNum[i];
                    break;
                }
            }
        }
        return res;
    }
};
