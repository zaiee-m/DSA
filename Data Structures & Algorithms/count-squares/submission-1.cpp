class CountSquares {
public:
    unordered_map<int, vector<int>> points_x;
    unordered_map<int, vector<int>> points_y;

    map<pair<int,int>, int> freqMap;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points_x[point[0]].push_back(point[1]);
        points_y[point[1]].push_back(point[0]);
        freqMap[{point[0], point[1]}] += 1;
    }
    
    int count(vector<int> point) {
        vector<int> x_aligned = points_x[point[0]];
        vector<int> y_aligned = points_y[point[1]];

        int count = 0;

        for(int i = 0; i < x_aligned.size(); i++){
            int x1 = point[0];
            int y1 = x_aligned[i];

            int x2a = point[0] + abs(point[1] - y1);
            int x2b = point[0] - abs(point[1] - y1);
            int y2 = point[1];

            if(freqMap.contains({x2a, y1}) && freqMap.contains({x2a, y2})){
                if(abs(x2a - x1) == abs(y1 - y2) &&
                abs(x2a - x1) != 0) count += freqMap[{x2a, y1}] * freqMap[{x2a, y2}];
            }


            if(freqMap.contains({x2b, y1}) && freqMap.contains({x2b, y2})){
                if(abs(x2b - x1) == abs(y1 - y2) &&
                abs(x2b - x1) != 0) count += freqMap[{x2b, y1}] * freqMap[{x2b, y2}];
            }

        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */