class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q;  // FOR STORING ROW AND COL

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int p=0;p<4;p++){
                    int nr=r+dir[p][0], nc=c+dir[p][1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && res[nr][nc]==-1){
                        res[nr][nc]=1+res[r][c];
                        q.push({nr,nc});
                    }
                }
                
            }
        }
        return res;

    }
};