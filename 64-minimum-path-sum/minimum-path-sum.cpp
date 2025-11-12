class Solution {
public:
    vector<vector<int>> dp;
    // RECURSION
    int helper1(vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0)
            return grid[m][n];

        if (m < 0 || n < 0)
            return INT_MAX;

        int right = helper1(grid, m, n - 1);
        int down = helper1(grid, m - 1, n);

        return grid[m][n] + min(right, down);
    }

    // MEMOIZATION
    int helper2(vector<vector<int>>& grid, int m, int n) {
        // if(m==0 && n==0)
        //     return grid[m][n];
        dp[0][0] = grid[0][0];

        if (m < 0 || n < 0)
            return INT_MAX;

        if (dp[m][n] != -1)
            return dp[m][n];

        int right = helper1(grid, m, n - 1);
        int down = helper1(grid, m - 1, n);

        return dp[m][n] = grid[m][n] + min(right, down);
    }

    // TABULATION
    int helper3(vector<vector<int>>& grid, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[0][0];
                else {
                    dp[i][j] = grid[i][j];
                    int right=INT_MAX,up=INT_MAX;
                    if(i-1>=0)
                        right=dp[i-1][j];
                    if(j-1>=0)
                        up=dp[i][j-1];
                    dp[i][j]+=min(right,up);
                    
                }
            }
        }
        return dp[m - 1][n - 1];
    }

                            // TABULATION SPACE OPT
    int helper5(vector<vector<int>>& grid, int m, int n) {
        vector<int>dp(grid[0].begin(),grid[0].end());
        for(int i=1;i<n;i++){
            dp[i]+=dp[i-1];
        }
        for (int i = 1; i < m; i++) {
            vector<int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    temp[j] = grid[i][j]+dp[j];
                else {
                    temp[j]=grid[i][j]+min(temp[j-1],dp[j]);
                    
                }
            }
            dp=temp;
        }
        return dp[n - 1];
    }

    //SPACE OPTIMIZED
    int helper4(vector<vector<int>> grid,int m,int n){

        for(int i=1;i<m;i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<n;i++){
            grid[0][i]+=grid[0][i-1];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m+1, vector<int>(n, -1));
        return helper5(grid, m , n );
    }
};