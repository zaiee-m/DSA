class Solution {
public:
    int jump(vector<int>& nums) {
    //------ Tokenisation ------

        // vector<int> dp(nums.size(), INT_MAX);
        // dp[0] = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = 0; j < i; j++){
        //         if(i > j + nums[j]) continue;
        //         dp[i] = min(dp[i], dp[j]+1);
        //     }
        // }
        // return dp.back();

    //------ Greedy Algorithm ------
        int min_steps = 0;
        int current_end = 0;
        int max_reach = 0;

        for(int i = 0; i < nums.size(); i++){
            max_reach = max(max_reach, i+nums[i]);
            if(i == current_end && i != nums.size()-1){
                min_steps++;
                current_end = max_reach;
            }
        }
        return min_steps;
    }
};