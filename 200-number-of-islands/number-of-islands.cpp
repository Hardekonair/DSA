class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        if(vis[row][col])
            return ;
        vis[row][col]=1;
        vector<int> tr={-1,1,0,0};
        vector<int> tc={0,0,-1,1};
        for(int i=0;i<4;i++){
                int r=row+tr[i],c=col+tc[i];
                if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1'&& vis[r][c]==0){
                    // vis[r][c]=1;
                    dfs(r,c,grid,vis);
                }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    c++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};