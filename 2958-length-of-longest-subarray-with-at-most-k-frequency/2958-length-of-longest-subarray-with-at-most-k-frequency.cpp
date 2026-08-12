class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int end = 0, start = -1 ;

        // vector<int> freq(1000000001,0);

        unordered_map<int,int> freq;

        int ans = end - start ;
        int maxi = 0;

        while(end<nums.size()){
            freq[nums[end]]++;
            
                while(freq[nums[end]]>k){
                    start++;
                    freq[nums[start]]--;
                    
                }
            
            ans = end - start ;
            maxi = max(ans,maxi);
            end++;
        }
        return maxi;
    }
};