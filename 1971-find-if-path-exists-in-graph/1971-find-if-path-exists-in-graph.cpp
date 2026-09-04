class Solution {
public:

    bool dfs(int n,unordered_map<int, vector<int>>& graph, int src, int dest, vector<bool>& vis){
        if(src == dest) return true;
        vis[src] = true;

        for(int i : graph[src]){
            if(!vis[i]){
                if(dfs(n, graph, i, dest, vis)) return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];

            graph[i].push_back(j);
            graph[j].push_back(i);
        }

        vector<bool> vis(n, false);

        return dfs(n, graph, source, destination, vis);
    }
};