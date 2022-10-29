class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> vp1, vp2;
        int m = img1.size();
        int n = img1[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (img1[i][j] == 1){
                    vp1.push_back({i,j});
                }
                if (img2[i][j] == 1){
                    vp2.push_back({i,j});
                }
            }
        }
        /*
        IMG 1       IMG 2
        1 1 0       0 0 0
        0 1 0       0 1 1
        0 1 0       0 0 1

        v1 = [ {0,0} , {0,1} , {1,1} , {2,1} ]
        v2 = [ {1,1} , {1,2} , {2,2} ]

        {0,0}  - {1,1}  = { -1 , -1 } 
        {0,1}  - {1,2}  = { -1 , -1 } 
        {1,1}  - {2,2}  = { -1 , -1 } 

        so the count of { -1 , -1 } is 3 .
        */
        int ans = 0;
        map<pair<int, int>, int> mp;
        for (auto p1:vp1){
            for (auto p2:vp2){
                int x = p1.first-p2.first;
                int y = p1.second-p2.second;
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        return ans;
    }
};
