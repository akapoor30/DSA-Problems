class Solution {
public:
    string smallestPalindrome(string s) {
        char c;
        if(s.size()%2==1){
            c = s[s.size()/2 ];
        }
        int n = s.size();
        sort(s.begin(),s.begin()+n/2);
        // int j = n-1;
        string ans ="";

        for(int i = 0;i<s.size()/2;i++){
            ans+=s[i];
        }
        s= ans;
        if(n%2==1){
            s+=c;
        }
        
        reverse(ans.begin(),ans.end());

        s+=ans;

        

        return s;


    }
};