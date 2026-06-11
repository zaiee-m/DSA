class Solution {
public:
    bool isHappy(int n) {
        auto sq_of_digs = [](int n){
            int sq = 0;
            while(n > 0){
                sq += pow((n%10),2);
                n = n/10;
            }
            return sq;
        };

        int current = n;
        while(true){
            if(current/10 == 0){
                return current == 1 || current == 7;
            }
            current = sq_of_digs(current);
        }
        return false;
    }
};