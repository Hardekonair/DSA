class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0]=1;

        if(grid[0][0]==1 || grid[n-1][n-1]==1)  
            return -1;
        if(n==1)
            return 1;
            
        vector<int> r={0,-1,-1,-1,0,1,1,1};
        vector<int> c={-1,-1,0,1,1,1,0,-1};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int k=0;k<8;k++){
                int nr=x+r[k];
                int nc=y+c[k];
                if(nr==n-1 && nc==n-1)
                    return 1+dis[x][y];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(dis[nr][nc]!=INT_MAX)    // FIRST REACHED DIS ALWAYS MIN IN BFS
                        continue;
                    else{
                        dis[nr][nc]=1+dis[x][y];
                        q.push({nr,nc});
                    }
                }
            }
        }

        // if(dis[n-1][n-1]==INT_MAX)  
            return -1;
        // return dis[n-1][n-1];

    }
};