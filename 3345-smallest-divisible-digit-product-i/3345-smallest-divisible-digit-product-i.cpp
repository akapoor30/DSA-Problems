class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n<101){
            int temp =n;
            int mul =1;
            while(temp){

                int num = temp%10;
                mul = mul * num;
                
                temp/=10;
            }
            if(mul % t ==0)return n;
            n++;
        }

        return 0;
    }
};