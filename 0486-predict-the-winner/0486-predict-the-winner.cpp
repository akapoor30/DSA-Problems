class Solution {
public:

    bool f(int i , int j, int p1, int p2, int turn , vector<int> nums){
        if(i>j)return p1>=p2;

        if((turn & 1) == 0){
            return f(i+1,j,p1+nums[i],p2,turn^1,nums) || f(i,j-1,p1+ nums[j],p2,turn^1,nums);
        }

        return f(i+1,j,p1,p2+nums[i],turn^1,nums) && f(i,j-1,p1,p2+ nums[j],turn^1,nums);
    }
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j=nums.size()-1 ,turn = 0;

        return f(i,j,0,0,turn, nums);
    }
};