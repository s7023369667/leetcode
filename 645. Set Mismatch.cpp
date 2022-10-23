class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(n+1);
        vector<int> res;
        for (int i=0;i<n;i++){
            table[nums[i]]++;
            if (table[nums[i]] > 1){
                res.push_back(nums[i]);
            }
        }
        for (int i=1;i<n+1;i++){
            if (table[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};
