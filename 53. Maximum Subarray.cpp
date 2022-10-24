class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int sumMax = INT_MIN;
        for (auto num: nums){
            currSum = max(num, currSum + num);
            sumMax = max(sumMax, currSum);
        }
        return sumMax;
    }
};
