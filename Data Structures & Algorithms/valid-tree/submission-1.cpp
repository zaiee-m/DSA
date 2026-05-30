class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);

        auto dfs = [&](auto &dfs, int node, int par){
            if(visited[node]) return false;
            visited[node] = true;

            for(auto nei: adj[node]){
                if(nei == par) continue;
                if(!dfs(dfs, nei, node)) return false;
            }
            // visited[node] = false;
            return true;
        };

        if(!dfs(dfs, 0, -1)) return false;
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
