class Solution {
public:
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        if (r*c != rows*cols || (rows==r && cols==c)){
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        int curr = 0;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                res[i][j] = mat[curr/cols][curr%cols];
                curr++;
            }
        }
        return res;
        
    }
    
};
