class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX;
        unordered_map<int,int> mp ;

        for(int i =0; i<nums.size() ; i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
            mp[nums[i]]++;
        }

        vector<int> ans;

        for(int i = mini+1;i<maxi;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};