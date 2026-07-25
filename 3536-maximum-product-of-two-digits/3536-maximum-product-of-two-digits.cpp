class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;

        while(n>0){
            vec.push_back(n%10);
            n/=10;
        }

        sort(vec.begin(),vec.end());

        int size = vec.size();

        return vec[size-1] * vec[size-2];
    }
};