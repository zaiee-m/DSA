class Solution {
    struct Point{
        int x;
        int y;

        Point(int x, int y){
            this->x = x;
            this->y = y;
        }

        float distance(){
            return ((float)x*x + (float)y*y);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](Point a, Point b){
            return a.distance() > b.distance();
        };

        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
        for(auto &point: points){
            pq.push(Point(point[0], point[1]));
        }
        vector<vector<int>> kpoints;
        for(int i = 0; i < k; i++){
            kpoints.push_back(vector<int>{pq.top().x, pq.top().y});
            pq.pop();
        }
        return kpoints;
    }
};