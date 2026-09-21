class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int i, int j, bool& x){
        if(i<0 || i>row-1 || j<0 || j>col-1){
            
           x =  false;
            return;
        }
        if(grid[i][j] == 1 || grid[i][j] == 2) return;

        grid[i][j] = 2;

        dfs(grid, row, col, i+1, j, x );
        dfs(grid, row, col, i-1, j, x );
        dfs(grid, row, col, i, j+1, x );
        dfs(grid, row, col, i, j-1,x );

    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i =0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 0){
                    bool x = true;
                    dfs(grid, row, col, i, j ,x);
                    if(x) count++;
                }
            }
        }
        return count;
    }
};