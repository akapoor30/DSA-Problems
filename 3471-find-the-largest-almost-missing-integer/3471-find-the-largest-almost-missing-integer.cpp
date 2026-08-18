class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        vector<int> count(51,0);

        for(int i = 0;i<nums.size();i++){
            count[nums[i]]++;
        }

        if(k==1){
            for(int i =50;i>=0;i--){
                if(count[i]==1)return i;
            }
            
            return -1;
            
        }

        int ans = -1;

        if(count[nums[0]]==1){
            ans = max(ans,nums[0]);
        }

        if(count[nums[nums.size()-1]]==1){
            ans = max(ans,nums[nums.size()-1]);
        }
        return ans ;
    }
};