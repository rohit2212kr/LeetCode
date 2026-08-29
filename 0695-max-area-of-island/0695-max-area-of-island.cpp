class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int row, int col){
        if(i<0 || i>=row || j<0|| j>=col|| grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        int area = 1;

        area += dfs(i+1, j, grid, row, col);
        area += dfs(i-1, j, grid, row, col);
        area += dfs(i, j+1, grid, row, col);
        area += dfs(i, j-1, grid, row, col);

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxi = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid, row, col);
                    maxi = max(area, maxi);
                }
            }
        }
        return maxi;
    }
};