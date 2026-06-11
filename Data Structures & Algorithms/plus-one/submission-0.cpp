class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> d = digits;
        reverse(d.begin(), d.end());
        int carry = 1;
        for(int i = 0; i < d.size(); i++){
            int sum = d[i] + carry;
            int dig = sum%10;
            carry = sum/10;
            d[i] = dig;
        }
        if(carry != 0) d.push_back(carry);
        reverse(d.begin(), d.end());
        return d;
    }
};