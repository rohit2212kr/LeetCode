class Solution {
public:
    void dfs(int n, int i, vector<vector<int>>& g){
        

        g[i][i] = 2;
        for(int j = 0; j<n; j++){
            if(g[i][j] == 1 && g[j][j] != 2){
                dfs(n, j, g);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        for(int i = 0; i< n; i++){
            if(isConnected[i][i] == 1){
                    count++;
                    dfs(n, i,  isConnected);
                }
        }
        return count;
    }
};