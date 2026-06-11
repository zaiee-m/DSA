class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dists(n, INT_MAX);
        vector<int> distsp(n, INT_MAX);

        dists[src] = 0;
        distsp[src] = 0;

        for(int i = 1; i <= k+1; i++){
            for(auto flight: flights){ 
                int a = flight[0];
                int b = flight[1];
                int w = flight[2];
                if(distsp[a] == INT_MAX) continue;
                dists[b] = min(distsp[a]+w,dists[b]);
            }
            distsp = dists;
        }

        return dists[dst] == INT_MAX? -1: dists[dst];
    }
};