class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(auto num: nums) pq.push(num);
        // for(int i = 0; i < k-1; i++) pq.pop();
        // return pq.top();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < k-1; i++){
            nums.pop_back();
        }
        return nums.back();
    }
};