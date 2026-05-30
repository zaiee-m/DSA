class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int,int>> queue;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 0) queue.push({i,j});
        }
        
        int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

        while(!queue.empty()){
            auto curr = queue.front(); queue.pop();
            int x = curr.first, y = curr.second;

            for(auto dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(
                    nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    grid[nx][ny] == INT_MAX 
                ){
                    grid[nx][ny] = grid[x][y] + 1;
                    queue.push({nx,ny});
                }
            }
        }
    }
};
