class Solution {
public:

    bool dfs(vector<vector<char>>& board, int row, int col, int i, int j){
        if(i<0 || i>row-1 || j<0 || j> col-1) return false;

        if(board[i][j] == 'X' || board[i][j] == 'v') return true;

        board[i][j] = 'v';

       bool a =  dfs(board, row, col, i+1, j);
       bool b =  dfs(board, row, col, i-1, j);
       bool c =  dfs(board, row, col, i, j+1);
       bool d =  dfs(board, row, col, i, j-1);

       return a && b && c && d;
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == 'O'){
                    if(dfs(board, row, col, i, j)){
                        for(int x = 0; x<row; x++){
                            for(int y = 0; y<col; y++){
                                if(board[x][y] == 'v') board[x][y] = 'X';
                            }
                        }
                    }
                    else{
                        for(int x = 0; x<row; x++){
                            for(int y = 0; y<col; y++){
                                if(board[x][y] == 'v') board[x][y] = 'O';
                            }
                        }

                    }
                }
            }
        }
    }
};