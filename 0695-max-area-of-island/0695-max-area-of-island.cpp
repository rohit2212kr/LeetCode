class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int row, int col, int& curr, int&count){
        if(i<0 || i>row-1 || j<0 || j>col-1 || grid[i][j] == 0 || grid[i][j] == 2){
            return;
        }
        grid[i][j] = 2;
        curr++;
        count = max(count, curr);
        dfs(grid, i+1, j, row, col, curr, count );
        dfs(grid, i-1, j, row, col, curr, count );
        dfs(grid, i, j+1, row, col, curr, count );
        dfs(grid, i, j-1, row, col, curr, count );
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int curr;
        int row = grid.size();
        int col =  grid[0].size();


        for(int i = 0; i<row; i++){
            for(int j = 0; j< col; j++){
                if(grid[i][j] == 1){
                    curr = 0;
                    dfs(grid, i, j, row, col, curr, count);
                    
                }
            }
        }
        return count;
    }
};