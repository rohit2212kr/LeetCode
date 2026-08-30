class Solution {
public:

    bool dfs(vector<vector<char>>& board, int row, int col, int i, int j){
        if(i < 0 || i >= row || j < 0 || j >= col)
            return false;

        if(board[i][j] == 'X' || board[i][j] == 'V')
            return false;

        if(i == 0 || i == row-1 || j == 0 || j == col-1)
            return true;

        board[i][j] = 'V';

        bool up = dfs(board, row, col, i-1, j);
        bool down = dfs(board, row, col, i+1, j);
        bool left = dfs(board, row, col, i, j-1);
        bool right = dfs(board, row, col, i, j+1);

        return up || down || left || right;
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(board[i][j] == 'O'){

                    bool boundary = dfs(board, row, col, i, j);

                    if(boundary){
                        // V → O
                        for(int x = 0; x < row; x++){
                            for(int y = 0; y < col; y++){
                                if(board[x][y] == 'V')
                                    board[x][y] = 'O';
                            }
                        }
                    }
                    else{
                        // V → X
                        for(int x = 0; x < row; x++){
                            for(int y = 0; y < col; y++){
                                if(board[x][y] == 'V')
                                    board[x][y] = 'X';
                            }
                        }
                    }
                }
            }
        }
    }
};