class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long int, int> mp;

        int one=0,ans = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                one++;
            }
            else{
                mp[nums[i]]++;
            }
        }

        if(one!=0 && one%2==0){
            one--;
        }
        ans = one;

        for(auto i:mp){
            long long int freq =i.first;
            long long int base = sqrt(freq);

            if(base*base == freq && mp.count(base) && mp[base]>1){
                continue;
            }
            int count = 0;

            while(mp.count(freq) && mp[freq]>1){
                count+=2;
                freq = freq*freq;
            }

            if(mp[freq]==1){
                count++;
            }
            else{
                count--;
            }

            ans = max(ans,count);

        }
        return ans;
    }
};