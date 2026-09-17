class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path, int i) {

        vis[i] = true;
        path[i] = true;

        for(int neighbour : adj[i]) {

            if(path[neighbour])
                return true;

            if(!vis[neighbour]) {
                if(dfs(adj, vis, path, neighbour))
                    return true;
            }
        }

        path[i] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);

        for(auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
        }

        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(adj, vis, path, i))
                    return false;
            }
        }

        return true;
    }
};