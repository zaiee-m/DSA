class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> formed{INT_MIN, INT_MIN, INT_MIN};
        for(auto triplet: triplets){
            int a = triplet[0], b = triplet[1], c = triplet[2];
            if(
                (a == target[0] || b == target[1] || c == target[2]) &&
                (a <= target[0] && b <= target[1] && c <= target[2])
            ){
                for(int i = 0; i < 3; i++){
                    formed[i] = max(formed[i], triplet[i]);
                }
            }
        }
        return formed == target;
    }
};