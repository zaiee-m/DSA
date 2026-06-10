class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        auto comp = [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
            return a.second > b.second;
        };
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, decltype(comp)> heap(comp);
        heap.push({{0,0}, grid[0][0]});
        visited[0][0] = true;
        int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!heap.empty()){
            pair<pair<int,int>,int> current = heap.top(); heap.pop();
            int x = current.first.first, y = current.first.second;
            int ht = current.second;
            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                return ht;
            }
            for(auto dir:dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(
                    nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() &&
                    !visited[nx][ny]
                ){
                    visited[nx][ny] = true;
                    int next_ht = max(ht, grid[nx][ny]);
                    heap.push({{nx,ny},next_ht});
                }
            }
        }
        return -1;
    }
};