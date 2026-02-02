class Solution {
public:
    int up3(int i,int j,int count,vector<vector<int>>& grid,vector<vector<int>>& vis){
        if(grid[i][j]==2 && count==1){
            return 1;
        }
        vis[i][j]=1;
        vector<int>r={1,0,0,-1};
        vector<int>c={0,-1,1,0};
        int ans=0;
        for(int k=0;k<4;k++){
            int ni=i+r[k], nj=j+c[k];
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]!=-1 && !vis[ni][nj]){
                if(grid[ni][nj]==2 && count!=2)
                    continue;
                ans=ans+up3(ni,nj,count-1,grid,vis);
            }
        }
        vis[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int r=0,c=0;
        int count=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && flag){
                        r=i,c=j;
                        flag=false;
                }
                if(grid[i][j]!=-1)
                    count++;
            }
        }
        return up3(r,c,count,grid,vis);
    }
};