class Solution {
    
    
public:
     
    int temp(int ans, int *see){
        while(ans!=see[ans]){
            see[ans] = see[see[ans]];
            ans=see[ans];
        }
        return ans;
    }
    
    int sol(int n, vector<vector<int>>& roads){
        int node[n],mn[n],res = INT_MAX;
        for(int i=0;i<n;i++){
            node[i] = i;
            mn[i] = INT_MAX;
        }
        for(int i=0;i<roads.size();i++){
            int x = roads[i][0]-1,y = roads[i][1]-1,z = roads[i][2];
            mn[x] = min(mn[x], z);  mn[y] = min(mn[y], z);
            
            node[temp(x,node)] = temp(y, node);
        }
        for(int i=0;i<n;i++){
            if(temp(i, node) == temp(0, node)){res = min(mn[i], res);}
        }
        return res;
    }
   
    int minScore(int n, vector<vector<int>>& roads) {
        
        return sol(n, roads);
    }
};