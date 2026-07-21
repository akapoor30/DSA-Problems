class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zero;
        int count1 = 0;
        int flag = 1;
        int temp=0;
        
        int i =0;
        while(i<s.size()){
            if(s[i]=='0'){
                int start =i;
                while(i<s.size() && s[i] == '0')i++;
                zero.push_back(i-start);
            }else{
                count1++;
                i++;
            }
        }
        for(int i =0;i<zero.size();i++){
            cout<<zero[i] ;
        }


        int ans = 0;
        
        for(int i =1;i<zero.size();i++){
            ans = max(ans,zero[i] + zero[i-1]);
            // cout<<zero[i] << " "<<zero[i+1];

        }
        
        return ans + count1;



    }
};  