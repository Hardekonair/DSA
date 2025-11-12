class Solution {
public:
    vector<vector<int>>dp;
    int helper1(vector<vector<int>>& grid,int m,int n){
        if(m==0 && n==0)
            return grid[m][n];
        
        if(m<0 || n<0)
            return INT_MAX;

        if(dp[m][n]!=-1)
            return dp[m][n];

        int right=helper1(grid,m,n-1);
        int down=helper1(grid,m-1,n);

        return dp[m][n]=grid[m][n]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return helper1(grid,m-1,n-1);
    }
};