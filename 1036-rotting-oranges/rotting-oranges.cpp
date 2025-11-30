class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            bool rot=false;
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                if(r-1>=0 && grid[r-1][c]==1){
                    rot=true;
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                }
                if(r+1<n && grid[r+1][c]==1){
                    rot=true;
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    rot=true;
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                }
                if(c+1<m && grid[r][c+1]==1){
                    rot=true;
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                }
            }
            if(rot)
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