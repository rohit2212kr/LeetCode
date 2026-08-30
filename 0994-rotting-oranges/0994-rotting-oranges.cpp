class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;;
        int count1 = 0;
        int row = grid.size();
        int col = grid[0].size();
        int time = 0;
        bool rot = false;

        for(int i = 0; i< row; i++){
            for(int j = 0; j< col; j++){

                if(grid[i][j] == 2) q.push({i,j});   
                if(grid[i][j] == 1) count1++;

            }
        }

        while(!q.empty()){
            int size = q.size();
            rot = false;
            while(size>0){
                int i = q.front().first;
                int j = q.front().second;

                if(i+1 < row && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    count1--;
                    rot = true;
                } 
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    count1--;
                    rot = true;
                } 
                if(j+1 < col && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    count1--;
                    rot = true;
                } 
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    count1--;
                    rot = true;
                } 

                q.pop();
                size--;
                

            }
            if(rot){

            time++;
            }
        }
        if(count1 != 0) return -1;
        else return time;
        
    }
};