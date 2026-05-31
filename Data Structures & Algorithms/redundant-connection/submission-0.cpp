#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> degree(n+1);
        vector<vector<int>> adj(n+1, vector<int>());

        for(auto edge: edges){
            int u = edge[0], v = edge[1];

            degree[v]++;
            degree[u]++;

            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        queue<int> queue;

        for(int i = 1; i < n+1; i++){
            if(degree[i] == 1){
                queue.push(i);
                degree[i]--;
            }
        }

        while(!queue.empty()){
            int node = queue.front(); queue.pop();

            for(auto nei: adj[node]){
                degree[nei]--;
                if(degree[nei] == 1) queue.push(nei);
            }
        }

        for(auto edge: views::reverse(edges)){
            int u = edge[0], v = edge[1];
            if(degree[u] == 2 && degree[v] == 2) return {u,v};
        }

        return {};
    }
};