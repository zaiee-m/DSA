class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> removed;
        removed.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(removed.back()[1] <= intervals[i][0]){
                removed.push_back(intervals[i]);
            }
        }
        return intervals.size() - removed.size();
    }
};