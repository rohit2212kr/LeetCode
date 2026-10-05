class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> ind(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(auto p : pre){
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }

        for(int i =0;i<n; i++){
            if(ind[i] == 0) q.push(i);
        }

        int count = 0;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;

            for(auto next : adj[top]){
                ind[next]--;

                if(ind[next] == 0) q.push(next);
            }

        }

        if(count == n) return true;
        else return false;

    }
};