class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> queue;

        int components = 0;

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            queue.push(i);
            visited[i] = true;

            components++;

            while(!queue.empty()){
                int curr = queue.front(); queue.pop();
                for(auto nei: adj[curr]){
                    if(visited[nei]) continue;
                    queue.push(nei);
                    visited[nei] = true;
                }
            }
        }
        
        return components;
    }
};
