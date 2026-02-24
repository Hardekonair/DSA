class Solution {
public:
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                    // vis[i][j]=1;
            }
        }
        int time=0;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int k=q.size();
            bool rotted=false;
            
            for(int l=0;l<k;l++){
                auto [i,j]=q.front();
                q.pop();
                for(auto it:dir){
                    int ni=i+it[0], nj=j+it[1];
                    if(isvalid(ni,nj,n,m) && grid[ni][nj]==1){
                        rotted=true;
                        q.push({ni,nj});
                        grid[ni][nj]=2;
                        // vis[i][j]=1;
                    }
                }
            }
            if(rotted)
                time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};