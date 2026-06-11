class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<int> dists(n, INT_MAX);
        // vector<int> distsp(n, INT_MAX);

        // dists[src] = 0;
        // distsp[src] = 0;

        // for(int i = 1; i <= k+1; i++){
        //     for(auto flight: flights){ 
        //         int a = flight[0];
        //         int b = flight[1];
        //         int w = flight[2];
        //         if(distsp[a] == INT_MAX) continue;
        //         dists[b] = min(distsp[a]+w,dists[b]);
        //     }
        //     distsp = dists;
        // }

        // return dists[dst] == INT_MAX? -1: dists[dst];

        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());

        for(auto flight: flights){
            int a = flight[0];
            int b = flight[1];
            int w = flight[2];

            adj[a].push_back({b,w});
        }

        vector<int> distances(n, INT_MAX);

        queue<int> q;
        q.push(src);

        distances[src] = 0;

        int levels = 0;
        while(!q.empty() && levels < k+1){
            levels++;
            int level = q.size();

            vector<int> prev_distances = distances;

            for(int i = 0; i < level; i++){
                int a = q.front(); q.pop();
                for(auto nei: adj[a]){
                    int b = nei.first;
                    int w = nei.second;
                    if (prev_distances[a] + w < distances[b]) {
                        distances[b] = prev_distances[a] + w;
                        q.push(b);
                    }
                }
            }
        }
        return distances[dst] == INT_MAX? -1: distances[dst];
    }
};