class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        map<int, int> mp;
        vector<int> ans;
        
        for (int i=0;i<n;i++){
            int tmp = target - nums[i];
            if (mp.find(tmp) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[tmp]);
            }
            mp[nums[i]] = i;
        }
        
        return ans;
        
    }
};
