class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxx_perimeter = 0;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if ((a+b>c) && (a+c>b) && (b+c>a)){
                if (maxx_perimeter < a+b+c){
                    maxx_perimeter = a+b+c;
                }
            }
        }
        return maxx_perimeter;
    }
};
