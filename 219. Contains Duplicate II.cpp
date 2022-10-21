class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        
        for (int i=0;i<n;i++){
            // TLE:
            // for (int j = i+1;j<=i+k && j<n;j++){
            //     if (nums[i] == nums[j]){
            //         return true;
            //     }
            // }
            if (ump.count(nums[i])){
                if (abs(i - ump[nums[i]]) <= k){
                    return true;
                }
            }
            ump[nums[i]] = i;
        }
        return false;
    }
};
