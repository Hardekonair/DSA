class Solution {
public:
vector<vector<int>>d={{1,0},{0,1},{-1,0},{0,-1}};
bool reachable(vector<vector<int>>& grid,int mid){
    priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>pq;

    int n=grid.size();
    vector<vector<int>>vis(n,vector<int>(n,0));

    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        auto [t,c]=pq.top();
        auto [x,y]=c;
        pq.pop();
        vis[x][y]==1;

        if(t>mid)return false;

        if(x==n-1 && y==n-1)
            return true;


        for(int i=0;i<4;i++){
            int nx=x+d[i][0], ny=y+d[i][1];
                if(nx<n && ny<n && nx>=0 && ny>=0 && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    int nt=max(t,grid[nx][ny]);

                    pq.push({nt,{nx,ny}});
                }
        }
    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=n*n;

        int l=0,r=ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(reachable(grid,mid)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    int swimInWater1(vector<vector<int>>& grid) {
        // SINCE STARTING AND ENDING POINT IS FIXED WE USE
        // SINGLE SOURCE SHORTEST PATH
        // DJIKSTRA ALGORITHM
        
        int n=grid.size();

        vector<vector<int>> res(n,vector<int>(n,1e9));

        priority_queue<pair<int,pair<int,int>>,         // {time,i,j}
                            vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>
                           > pq;

        pq.push({grid[0][0],{0,0}});
        res[0][0]=grid[0][0];
        vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            
            if(r==n-1 && c==n-1)    
                return t;

            if(t>res[r][c])
                continue;

            for(int i=0;i<4;i++){
                int nr=r+d[i][0], nc=c+d[i][1];
                if(nr<n && nc<n && nr>=0 && nc>=0){
                    int nt=max(grid[nr][nc],t);
                    if(nt<res[nr][nc]){
                        res[nr][nc]=nt;
                        pq.push({nt,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};