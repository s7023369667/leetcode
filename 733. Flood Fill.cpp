class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> visit_table(row, vector<int>(col, 0));
        BFS(image, row, col, sr, sc, image[sr][sc], color, visit_table);
        return image;
    }
    
    void BFS(vector<vector<int>>& image, int row, int col, int r, int c, 
             int old_color,int new_color, vector<vector<int>>& visit_table){
        // cout << "(" << r << "," << c << ")" << endl;
        if (r<0 || r>=row || c<0 || c>=col || image[r][c]!=old_color || visit_table[r][c]==1){
            return;
        }
        image[r][c] = new_color;
        visit_table[r][c] = 1;
        // for (int i=0;i<row;i++){
        //     for (int j=0;j<col;j++){
        //         cout << image[i][j] << "\t";
        //     }
        //     cout<< endl;
        // }
        // cout<<endl;
        BFS(image, row, col, r+1, c, old_color, new_color, visit_table);
        BFS(image, row, col, r-1, c, old_color, new_color, visit_table);
        BFS(image, row, col, r, c+1, old_color, new_color, visit_table);
        BFS(image, row, col, r, c-1, old_color, new_color, visit_table);
    }
    
};
