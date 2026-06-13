class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        if(n < 0){
            if(n == INT_MIN) return x * myPow(1/x, INT_MAX);
            else return myPow(1/x, -n);
        }
        else{
            if(n%2 == 0) return myPow(pow(x,2), n/2);
            else return x * myPow(pow(x,2),(n-1)/2);
        }
    }
};