class Solution {
public:
    int dp[51][51][102];
    bool solve(int i,int j,int h,vector<vector<int>>& grid,vector<vector<int>>& vis){
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1)   
            return false;
        h=h-grid[i][j];
        if(h<1)
            return false;
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return true;
        if( vis[i][j] == 1 ) 
            return false;

        if(dp[i][j][h]!=-1)
            return dp[i][j][h];

        vis[i][j]=1;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto it:dir){
            int ni=i+it[0], nj=j+it[1];
            if(solve(ni,nj,h,grid,vis)) 
                return dp[i][j][h]=true;
        }
        vis[i][j]=0;
        return dp[i][j][h]=false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        return solve(0,0,health,grid,vis);
    }
};