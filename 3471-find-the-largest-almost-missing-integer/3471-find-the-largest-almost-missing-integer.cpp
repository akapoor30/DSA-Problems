//[3,9,2,1,7] i = 0, j = 0, k = 3;
// j = 1 
// j=2
// 9->2
// 3->1
// 2->3
// 1->2
// 7->1

// [3,9,2] 
// [9,2,1]
// [2,1,7]

// [0,0]

// k = 2

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        unordered_map<int,int> mp;

        for(int i =0;i<=nums.size()-k;i++){
            unordered_set<int> unique;
            // if(i+k<nums.size())break;
            for(int j = i;j<i+k;j++){
               unique.insert(nums[j]);
            }

            for(auto j : unique){
                mp[j]++;
            }

        }

        for(auto i:mp){
            if(i.second==1){
                cout<<i.first;
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};