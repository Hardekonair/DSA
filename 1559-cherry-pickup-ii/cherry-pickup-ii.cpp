class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
            return 0;
        
        if(i==grid.size()-1){
            if(j1==j2)
                return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int alice=-1;alice<=1;alice++){
            for(int bob=-1;bob<=1;bob++){
                int temp=0;
                if(j1==j2)
                    temp+=grid[i][j1]+helper(i+1,j1+alice,j2+bob,grid);
                else
                    temp+=grid[i][j1]+grid[i][j2]+helper(i+1,j1+alice,j2+bob,grid);
                
                maxi=max(maxi,temp);
            }
            dp[i][j1][j2]=maxi;
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return helper(0,0,grid[0].size()-1,grid);
    }
};