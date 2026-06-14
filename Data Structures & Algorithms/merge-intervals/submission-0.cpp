class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int> last_interval = result.back();
            if(last_interval[1] < intervals[i][0]) result.push_back(intervals[i]);
            else{
                result.pop_back();
                vector<int> new_interval(2);
                new_interval[0] = min(last_interval[0],intervals[i][0]);
                new_interval[1] = max(last_interval[1],intervals[i][1]);
                result.push_back(new_interval);
            }
        }
        return result;
    }
};