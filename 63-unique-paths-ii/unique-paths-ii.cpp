class Solution {
public:
    vector<vector<int>> dp;
    int helper1(vector<vector<int>>& grid,int m,int n){
        if(m<0 || n<0)
            return 0;
        if(grid[m][n]==1)
            return 0;
        if(m==0 && n==0)
            return 1;
        
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int left=helper1(grid,m,n-1);
        int up=helper1(grid,m-1,n);

        return dp[m][n]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));

        return helper1(grid,grid.size()-1,grid[0].size()-1);
    }
};