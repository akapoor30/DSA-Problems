class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp(n*m);
        
        int ind = 0;
        
        // 1%9
        // 2%9
        // 3%9
        // 4%9
        // 5%9
        // 6%9
        // 7%9
        // 8%9
        // 9%9
        // 10%9

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(ind != temp.size()){
                    temp[k%temp.size()] = grid[i][j];
                    ind++;
                    k++; 
                }
            }
        }

        ind = 0;

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = temp[ind++];
            }

        }

        return grid;

    }
};