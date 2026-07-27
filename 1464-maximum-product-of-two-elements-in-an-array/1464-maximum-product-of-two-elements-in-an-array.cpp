class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=(nums.at(nums.size()-1)-1)*(nums.at(nums.size()-2)-1);
        return n;
    }
};