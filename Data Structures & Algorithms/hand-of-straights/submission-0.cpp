class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        for(int i = 0; i < hand.size(); i++) m[hand[i]]++;
        for(auto &[key, value]: m){
            if (value == 0) continue;
            int count = value;
            for(int i = 0; i < groupSize; i++){
                if(m[key+i] < count) return false;
            }
            for(int i = 0; i < groupSize; i++){
                m[key+i] -= count;
            }
        }
        return true;
    }
};