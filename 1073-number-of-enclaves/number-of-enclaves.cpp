class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid){
        grid[r][c]=0;
        
        vector<int>tr={-1,1,0,0};
        vector<int>tc={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=r+tr[i];
            int nc=c+tc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1)
                dfs(nr,nc,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                dfs(i,0,grid);
            if(grid[i][m-1]==1)
                dfs(i,m-1,grid);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1)
                dfs(0,j,grid);
            if(grid[n-1][j]==1)
                dfs(n-1,j,grid);
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)   
                    count++;
            }
        }
        return count;
    }
};