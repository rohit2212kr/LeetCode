class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int i, int j, int& peri){
        if(i<0 || i>=row || j <0 || j>=col || grid[i][j] == 0){
            peri++;
            return;
        }
        if(grid[i][j] == 2) return;
        grid[i][j] = 2;

        dfs(grid, row, col, i+1, j, peri);
        dfs(grid, row, col, i-1, j, peri);
        dfs(grid, row, col, i, j+1, peri);
        dfs(grid, row, col, i, j-1, peri);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    dfs(grid, row, col, i, j, peri);
                }
            }
        }
        return peri;
    }
};