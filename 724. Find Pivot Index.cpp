class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int N = nums.size();
        int leftSum[N];
        //left to right find leftSum
        leftSum[0] = 0;
        for (int i=1;i<N;i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        //right to left find leftSum
        int rightSum[N];
        rightSum[N-1] = 0;
        for (int i=N-2;i>=0;i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        // for (int i=0;i<N;i++){
        //     cout << leftSum[i] << ", ";
        // }
        // cout << endl;
        // for (int i=0;i<N;i++){
        //     cout << rightSum[i] << ", ";
        // }
        // cout << endl;
        for (int i=0;i<N;i++){
            if (leftSum[i] == rightSum[i]){
                pivot = i;
                break;
            }
        }

        return pivot;
    }
};
