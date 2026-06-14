/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for(auto interval: intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
    
        int max_count = 0;

        for(int e = 0; e < ends.size(); e++){
            int count = 0;
            int s = e;
            while(s < starts.size() && starts[s] < ends[e]){
                s++;
                count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
