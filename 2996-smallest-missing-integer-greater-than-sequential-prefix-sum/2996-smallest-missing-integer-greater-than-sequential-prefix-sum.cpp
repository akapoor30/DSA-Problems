class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int preSum = nums[0];
        unordered_set mp(nums.begin(),nums.end());

        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                preSum+=nums[i];
            }
            else{
                break;
            }
        }
        cout<<preSum;
        while(mp.count(preSum)){
            preSum++;
        }

        return preSum;
    }
};