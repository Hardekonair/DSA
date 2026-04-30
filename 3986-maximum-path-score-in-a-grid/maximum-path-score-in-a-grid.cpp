class Solution {
public:
    // int dp[201][201][1001];
    vector<vector<vector<int>>>dp;
    int solve(int i,int j,int m,int n, vector<vector<int>>& grid, int k){
        if(i<0 || j<0 || i>=m || j>=n)
            return INT_MIN;
        k=k-(grid[i][j]!=0);
        if(k<0) 
            return INT_MIN;
        if(i==m-1 && j==n-1)
            return grid[i][j];
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
            
        int temp=max(solve(i+1,j,m,n,grid,k),solve(i,j+1,m,n,grid,k));
        if(temp==INT_MIN)   return dp[i][j][k]=INT_MIN;

        return dp[i][j][k]=grid[i][j]+temp;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        // memset(dp,-1,sizeof(dp));
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans=solve(0,0,m,n,grid,k);
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};