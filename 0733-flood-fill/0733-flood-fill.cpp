class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int row, int col, int src){
        if(sr < 0 || sr>row-1 || sc <0 || sc > col-1 || image[sr][sc] == color || image[sr][sc] != src) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc,  color, row, col, src);
        dfs(image, sr-1, sc,  color, row, col, src);
        dfs(image, sr, sc+1,  color, row, col, src);
        dfs(image, sr, sc-1,  color, row, col, src);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row =  image.size();
        int col = image[0].size();
        int src = image[sr][sc];
        dfs(image, sr, sc,  color, row, col, src);
        return image; 
    }
};