class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k){
            if (abs(res.front() - x) <= abs(res.back() - x)){
                res.pop_back();
            }else{
                res.erase(res.begin());
            }
        }
        return res;
    }
};
