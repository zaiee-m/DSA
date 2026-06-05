class Solution {
public:
    bool checkValidString(string s) {
    //------ Memoisation ------

        // int open_count = 0;
        // vector<vector<int>> dp(s.size(), vector<int>(s.size()+1, -1));
        
        // auto backtrack = [&](auto &self, int i, int open_count) -> bool{
        //     if(i == s.size()) return open_count == 0;
        //     if(dp[i][open_count] != -1) return dp[i][open_count];
        //     dp[i][open_count] = 0;
        //     if(s[i] == '(') {
        //         if(self(self, i+1, open_count+1)) dp[i][open_count] = 1;
        //     }
        //     else if(s[i] == ')'){
        //         if(open_count != 0) {
        //             if(self(self, i+1, open_count-1)) dp[i][open_count] = 1;
        //         }
        //     }
        //     else{
        //         if(self(self, i+1, open_count+1)) return dp[i][open_count] = 1;
        //         if(open_count != 0){
        //             if(self(self, i+1, open_count-1)) return dp[i][open_count] = 1;
        //         }
        //         if(self(self, i+1, open_count)) return dp[i][open_count] = 1;
        //     }
        //     return dp[i][open_count];
        // };

        // return backtrack(backtrack, 0, 0);
    
    //------ Greedy Algorithm ------
        int min_count = 0;
        int max_count = 0;
        for(auto c: s){
            if(c == '(') {min_count++; max_count++;}
            else if(c == ')') {min_count--; max_count--;}
            else {min_count--; max_count++;}

            if(min_count < 0) min_count = 0;
            if(max_count < 0) return false;
        }
        return min_count == 0;
    }
};