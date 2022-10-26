class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mp1;
        for (int n1:nums1){
            mp1[n1]++;
        }
        for (int n2:nums2){
            if (mp1[n2]){
                res.push_back(n2);
                mp1[n2]--;
            }
        }
        return res;
    }
};
