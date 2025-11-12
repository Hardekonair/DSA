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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return helper3(grid, m , n );
    }
};