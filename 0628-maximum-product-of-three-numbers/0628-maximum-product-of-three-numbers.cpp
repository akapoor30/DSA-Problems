class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mini1 =INT_MAX,mini2 = INT_MAX;

        int maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;

        sort(nums.begin(),nums.end());

        // for(int i = 0;i<nums.size();i++){
        //     mini1 = min(mini1 , nums[i]);

        //     if(mini2>nums[i] && mini1<nums[i]){
        //         mini2 = nums[i];
        //     }

        //     maxi1 = max(maxi1,nums[i]);

        //     if(maxi2 > nums[i] && maxi1 > nums[i]){
        //         maxi2 = nums[i];
        //     }

        //     if(maxi3 > nums[i] && maxi2 > nums[i]){
        //         maxi3 = nums[i];
        //     }
        // }
        // cout<< maxi1 << " "<< maxi2 << " "<<maxi3<< " "<<mini1<<" "<<mini; 
        int n = nums.size();

        int p1 = nums[n-1] * nums[0] * nums[1];
        int p2 = nums[n-1] * nums[n-2] * nums[n-3];
        cout<<p1<<" "<<p2;
        return (p1 > p2) ? p1 : p2;
    }
};