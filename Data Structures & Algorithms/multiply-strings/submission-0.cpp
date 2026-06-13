class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        auto addTwoStringNumbers = [](string a, string b) -> string{
            string small = b, big = a;
            if(a.size() < b.size()) {
                small = a;
                big = b;
            }

            reverse(small.begin(), small.end());
            reverse(big.begin(), big.end());

            string sumStr = "";
            int carry = 0;

            for(int i = 0; i < big.size(); i++){
                int a, b;

                if(i < small.size()) a = small[i] - '0';
                else a = 0;
                b = big[i] - '0';

                int sum = a + b + carry;
                int dig = sum%10;
                carry = sum/10;

                sumStr.push_back(dig + '0');
            }

            if(carry != 0) sumStr.push_back(carry + '0');
            reverse(sumStr.begin(), sumStr.end());
            return sumStr;
        };

        string small = num2, big = num1;
        if(num1.size() < num2.size()) {
            small = num1;
            big = num2;
        }

        reverse(small.begin(), small.end());
        reverse(big.begin(), big.end());
        
        string running_sum = "";

        for(int i = 0; i < small.size(); i++){
            string inner_prod = "";
            int a = small[i] - '0';
            int carry = 0;
            for(int j = 0; j < big.size(); j++){
                int b = big[j] - '0';
                int prod = a*b + carry;
                
                int dig = prod%10;
                carry = prod/10;

                inner_prod.push_back(dig + '0');
            }
            if (carry != 0) {
                inner_prod.push_back(carry + '0');
            }
            reverse(inner_prod.begin(), inner_prod.end());
            for(int j = 0; j < i; j++) inner_prod.push_back('0');
            running_sum = addTwoStringNumbers(running_sum, inner_prod);
        }

        return running_sum;
    }
};