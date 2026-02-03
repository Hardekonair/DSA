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
    int fn(vector<vector<int>>& grid,int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(grid[0][0]==1)
            return 0;
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(grid[i][0]==0)
                dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            if(grid[0][i]==0)
                dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1)
                    continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

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

                                        // TABULATION - SC- O(N);
    int helper4(vector<vector<int>>& grid,int m,int n){
        vector<int> prevdp(n,1);
        for(int i=1;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    temp[j]=0;
                    continue;
                }
                temp[j]+=prevdp[j];
                if(j-1>=0)
                    temp[j]+=temp[j-1];
            }
            prevdp=temp;
        }
        return prevdp[n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));

        // return helper3(grid,grid.size(),grid[0].size());
        return fn(grid,m,n);
    }
};