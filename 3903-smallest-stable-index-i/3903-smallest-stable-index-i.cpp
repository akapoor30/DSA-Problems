class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1,mini=0;
        for(int i = 0 ;i<nums.size();i++){
            int maxi = INT_MIN, mini = INT_MAX;
            for(int j=0;j<=i;j++){
                maxi = max(maxi,nums[j]);
            }
            for(int j=i;j<nums.size();j++){
                mini = min(mini,nums[j]);
            }
            
            if((maxi-mini) <= k){
                return i;
                
            }

        }

        return ans;
    }
};