class Solution {
public:
    int maximumLengthSubstring(string s) {
        int end = 0, start =-1;
        unordered_map<char,int> mp;
        int ans = 0;

        while(end<s.size()){
            mp[s[end]]++;

            while(mp[s[end]]>2){
                start++;
                mp[s[start]]--;
            }

            ans = max(ans , end - start);
            end++;
        }
        return ans;
    }
};