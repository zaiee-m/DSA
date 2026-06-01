class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum =  INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], nums[i]+sum);
            // Equivalent to
            // if(sum < 0)
            //     sum = 0;
            // sum += array[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};