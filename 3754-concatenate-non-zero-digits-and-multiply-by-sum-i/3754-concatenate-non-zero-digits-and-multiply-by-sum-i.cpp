class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0,place =1,sum=0;
        string temp = "";

        while(n>0){
            int digit = n % 10; // Get the last digit
        
            if (digit != 0) {
                num += digit * place; // Add it to our new number
                place *= 10;    
                sum+=digit;
            }
                n/=10;

        }
        cout<<num<<" "<<sum;

        return num * sum;
    }
};