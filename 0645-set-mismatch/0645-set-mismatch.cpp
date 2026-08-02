class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);

        vector<int> temp(nums.size()+1,0);

        for(int i = 0;i<nums.size();i++){
            temp[nums[i]]++;
        }

        for(int i =1;i<temp.size();i++){
            if(temp[i]==2)ans[0]=i;
            if(temp[i]==0)ans[1]=i;
        }

        return ans;
    }
};