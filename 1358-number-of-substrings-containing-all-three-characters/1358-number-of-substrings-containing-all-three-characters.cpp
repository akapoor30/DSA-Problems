class Solution {
public:
    int numberOfSubstrings(string s) {
        int total = (s.size()*(s.size()+1))/2;

        int lastA= -1;
        int lastB = -1;
        int lastC = -1;

        int ans =0;

        for(int right = 0; right<s.size();right++){
            if(s[right]=='a')lastA = right;
            else if (s[right] == 'b' )lastB = right;
            else if (s[right] == 'c') lastC = right;

            if(lastA != -1 && lastB !=-1 && lastC !=-1){
                int leftBound = min(lastA,min(lastB,lastC));

                ans += leftBound+1;
            }
        }

        return ans;
    }
};