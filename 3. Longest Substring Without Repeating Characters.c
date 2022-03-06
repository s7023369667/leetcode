// //Brute Force
// bool checkRepetitions(char* s, int start, int end){
//     char* ascii[128]={0};
//     for (int i = start;i<=end;i++){
//         ascii[s[i]]++;
//         if (ascii[s[i]] > 1){
//             return false;
//         }
//     }
//     return true;
// }
// int lengthOfLongestSubstring(char* s) {
//     int len = strlen(s);
//     int res = 0;
//     for (int i=0;i<len;i++){
//         for (int j=i;j<len;j++){
//             if (checkRepetitions(s, i, j)){
//                 if (j-i+1 > res){
//                     res = j-i+1;
//                 }
//             }
//         }
//     }
//     return res;
// }

//sliding window

int lengthOfLongestSubstring(char* s) {
    char* ascii[128]={0};
    int left = 0, right = 0, res = 0; 
    int len = strlen(s);
    while (right < len){
        ascii[s[right]]++;
        while (ascii[s[right]] > 1){
            ascii[s[left]]--;
            left++;
        }
        res = right - left +1 > res ? right - left +1 : res;
        right ++;
    }
    return res;
}


