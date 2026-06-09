class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
        for(auto &edge: times){
            adj[edge[0]].push_back({edge[2], edge[1]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        
        vector<int> distances(n+1, INT_MAX);
        distances[k] = 0;

        while(!pq.empty()){
            int currNode = pq.top().second; pq.pop();
            for(auto &nei: adj[currNode]){
                int node = nei.second;
                int dist = nei.first;
                if (distances[currNode] + dist < distances[node]) {
                    distances[node] = distances[currNode] + dist;
                    pq.push({distances[node], node});
                }
            }
        }

        int min_time = 0;
        for(int i = 1; i < distances.size();i++){
            min_time = max(min_time, distances[i]);
        }

        return min_time == INT_MAX? -1: min_time; 
    }
};