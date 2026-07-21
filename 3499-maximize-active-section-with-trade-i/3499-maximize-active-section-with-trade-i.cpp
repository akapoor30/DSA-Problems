class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zero;
        int count1 = 0;
        int flag = 1;
        int temp=0;
        
        for(int i = 0; i<s.size();i++){
            int start =i;
            if(s[i]=='0'){
                while(i<s.size() && s[i] == '0'){
                    i++;
                }
                zero.push_back(i-start);
                i--;
            }
            else{
                count1++;
            }
        }
        // if(temp>0)
        //     zero.push_back(temp);
        for(int i =0;i<zero.size();i++){
            cout<<zero[i] ;
        }


        int ans = 0;
        
        for(int i =0;i<(int)zero.size()-1;i++){
            ans = max(ans,zero[i] + zero[i+1]);
            // cout<<zero[i] << " "<<zero[i+1];

        }
        
        return ans + count1;



    }
};  