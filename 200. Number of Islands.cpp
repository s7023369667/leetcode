class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visit_table(row, vector<int>(col, 0));
        int islandNum = 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]=='1' && visit_table[i][j]==0){
                    islandNum++;
                }
                BFS(grid, row, col, i, j, visit_table);
            }
        }
        return islandNum;
    }
    void BFS(vector<vector<char>>& grid, int row, int col, int r, int c, 
            vector<vector<int>>& visit_table){
        // cout << "(" << r << "," << c << ")" << endl;
        if (r<0 || r>=row || c<0 || c>=col || grid[r][c]=='0' || visit_table[r][c]==1){
            return;
        }
        visit_table[r][c] = 1;
        grid[r][c] = '0';
        
        // for (int i=0;i<row;i++){
        //     for (int j=0;j<col;j++){
        //         cout << grid[i][j] << "\t";
        //     }
        //     cout<< endl;
        // }
        // cout<<endl;
        BFS(grid, row, col, r-1, c, visit_table);
        BFS(grid, row, col, r+1, c, visit_table);
        BFS(grid, row, col, r, c-1, visit_table);
        BFS(grid, row, col, r, c+1, visit_table); 
    }
};
