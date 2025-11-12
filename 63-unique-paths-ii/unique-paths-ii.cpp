class Solution {
public:
    vector<vector<int>> dp;

                            // RECURSION
    int helper1(vector<vector<int>>& grid,int m,int n){
        if(m<0 || n<0)
            return 0;
        if(grid[m][n]==1)
            return 0;
        if(m==0 && n==0)
            return 1;
        
        int left=helper1(grid,m,n-1);
        int up=helper1(grid,m-1,n);

        return left+up;
    }

                                // MEMOIZATION
    int helper2(vector<vector<int>>& grid,int m,int n){
        if(m<0 || n<0)
            return 0;
        if(grid[m][n]==1)
            return 0;
        if(m==0 && n==0)
            return 1;
        
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int left=helper2(grid,m,n-1);
        int up=helper2(grid,m-1,n);

        return dp[m][n]=left+up;
    }

                                // TABULATION - NON RECURSIVE
    int helper3(vector<vector<int>>& grid,int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;

                }
                if(i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));

        return helper3(grid,grid.size(),grid[0].size());
    }
};