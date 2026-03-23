class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();

        vector<vector<int>>dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});

        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};         // IMP FOR EFFICIENCT
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(auto it:dir){
                int nx=x+it[0],ny=y+it[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int neff=max(dis[x][y],abs(h[x][y]-h[nx][ny]));
                    if(dis[nx][ny]>neff){
                        dis[nx][ny]=neff;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
    // int minimumEffortPath(vector<vector<int>>& heights) {
    //     int n=heights.size(), m=heights[0].size();

    //     priority_queue<pair<int,pair<int,int>>,
    //                         vector<pair<int,pair<int,int>>>,
    //                         greater<pair<int,pair<int,int>>>
    //                     >pq;

    //     vector<vector<int>>dis(n,vector<int>(m,1e9));
    //     dis[0][0]=0;         // IMP FOR EFFICIENCT

    //     pq.push({0,{0,0}});
    //     int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};         // IMP FOR EFFICIENCT
    //     while(!pq.empty()){
    //         auto [e,pos]=pq.top();
    //         auto [i,j]=pos;
    //         pq.pop();

            

    //         if(i==n-1 && j==m-1)
    //             return e;

    //         if(e>dis[i][j])         // IMP FOR EFFICIENCT
    //             continue;
    //         for(auto &it:dir){         // IMP FOR EFFICIENCT
    //             int ni=i+it[0], nj=j+it[1];
    //             if(ni>=0 && ni<n && nj>=0 && nj<m){
    //                 int eff=abs(heights[i][j]-heights[ni][nj]);
    //                 int neff=max(eff,e);
    //                 if(neff<dis[ni][nj]){
    //                     pq.push({neff,{ni,nj}});
    //                     dis[ni][nj]=neff;
    //                 }
    //             }
    //         }

    //     }
    //     return -1;
    // }
};