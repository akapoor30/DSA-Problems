class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int prod = 1, sum = 0;
        while(n>0){
            int temp = n%10;
            prod*=temp;
            sum+=temp;
            n/=10;
        }
        return num%(sum+prod) == 0 ? true : false;
    }
};