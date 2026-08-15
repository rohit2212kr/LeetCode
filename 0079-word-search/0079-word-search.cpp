class Solution {
public:
    bool btrack(int row, int col, int index,
                vector<vector<char>>& board,
                vector<vector<bool>>& used,
                string& word) {

        // We found the complete word
        if (index == word.size()) {
            return true;
        }

        // Out of bounds
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Already used or wrong character
        if (used[row][col] || board[row][col] != word[index]) {
            return false;
        }

        // Choose this cell
        used[row][col] = true;

        // Explore 4 directions
        if (btrack(row + 1, col, index + 1, board, used, word) ||
            btrack(row - 1, col, index + 1, board, used, word) ||
            btrack(row, col + 1, index + 1, board, used, word) ||
            btrack(row, col - 1, index + 1, board, used, word)) {

            return true;
        }

        // Undo the choice
        used[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> used(rows, vector<bool>(cols, false));

        // Every cell can potentially be the starting point
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (btrack(r, c, 0, board, used, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};