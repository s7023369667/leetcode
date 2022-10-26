class Solution {
public:
    bool bruce_force(vector<int>& nums, int k){
        //TLE
        int n = nums.size();
        for (int i=0;i<n-1;i++){
            int tmpSum = nums[i];
            for (int j=i+1;j<n;j++){
                tmpSum += nums[j];
                if (tmpSum % k ==0){
                    return true;
                }
            }
        }
        return false;
    }
    bool hashmap_solution(vector<int>& nums, int k){
        map<int, int> mp;
        mp[0] = -1;
        int tmpSum = 0;
        for (int i=0;i<nums.size();i++){
            tmpSum = (tmpSum + nums[i]) % k;
            if (mp.find(tmpSum) != mp.end()){
                if (i - mp[tmpSum] > 1){
                    return true;
                }
            }else{
                mp[tmpSum] = i;
            }
        }
        return false;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        return hashmap_solution(nums, k);
    }
};
