class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mini1 =INT_MAX,mini2 = INT_MAX;

        int maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;

        // sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i++){
            if(maxi1<=nums[i]){
                maxi3 = maxi2;
                maxi2= maxi1;
                maxi1=nums[i];
            }
            else if(nums[i]>=maxi2){
                maxi3 = maxi2;
                maxi2= nums[i];
            }
            else if(nums[i] >=maxi3){
                maxi3= nums[i];
            }

            if(nums[i]<=mini1){
                mini2= mini1;
                mini1= nums[i];
            }
            else if(nums[i]<=mini2){
                 mini2= nums[i];
            }
            
        }
        // cout<< maxi1 << " "<< maxi2 << " "<<maxi3<< " "<<mini1<<" "<<mini; 
        // int n = nums.size();

        int p1 = maxi1*mini1*mini2;
        int p2 = maxi1*maxi2*maxi3;
        cout<<p1<<" "<<p2;
        return (p1 > p2) ? p1 : p2;
    }
};