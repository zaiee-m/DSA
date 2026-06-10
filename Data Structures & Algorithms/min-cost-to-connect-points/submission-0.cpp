class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        auto comp = [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
            return a.second > b.second;
        };

        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, decltype(comp)> heap; 

        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];

                heap.push({{i,j}, abs(x1-x2) + abs(y1-y2)});
            }
        }

        vector<int> link(points.size());
        vector<int> size(points.size());

        for(int i = 0; i < points.size(); i++){
            link[i] = i;
            size[i] = 1;
        }

        auto find = [&link, &size](int x) -> int{
            while(link[x] != x) x = link[x];
            return x;
        };

        auto same = [&link, &size, &find](int a, int b) -> bool{
            return find(a) == find(b);
        };

        auto unite = [&link, &size, &find](int a, int b){
            a = find(a);
            b = find(b);

            if(size[a] >= size[b]){
                link[b] = a;
                size[a] += size[b];
            }
            else{
                link[a] = b;
                size[b] += size[a];
            }
        };

        int min_cost = 0;

        while(!heap.empty()){
            pair<pair<int,int>,int> current = heap.top(); heap.pop();
            int a = current.first.first, b = current.first.second;
            int length = current.second;

            if(!same(a,b)){
                unite(a, b);
                min_cost += length;
            }

            if(size[find(a)] == points.size()) return min_cost;
        }

        return 0;
    }
};