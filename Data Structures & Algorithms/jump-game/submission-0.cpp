class Solution {
public:
    bool canJump(vector<int>& nums) {
    
    //----- Dynamic Programming -----

        // vector<int> dp(nums.size(), -1);

        // auto recurse = [&](auto &self, int idx){
        //     if(dp[idx] != -1) return dp[idx];

        //     if(idx == nums.size()-1) {dp[idx] = 1; return dp[idx];}
        //     else if(nums[idx] == 0) {dp[idx] = 0; return dp[idx];}

        //     for(int i = 1; i <= nums[idx]; i++){
        //         if(idx + i < nums.size()){
        //             dp[idx] = self(self, idx+i);
        //             if(dp[idx]) break;
        //         }
        //     }

        //     return dp[idx];
        // };

        // return recurse(recurse, 0);


    //----- Greedy Algorithm -----

        int maxReachable = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxReachable) return false;
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};